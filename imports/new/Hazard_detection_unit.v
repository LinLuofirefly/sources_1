`timescale 1ns / 1ps
`include "defines.v"

// ============================================================================
// 流水线冒险检测单元
// ----------------------------------------------------------------------------
// 本模块只负责产生前端流水线控制信号：
//   hold_flag_o  ：保持 PC / IF-ID 等前端状态，阻止后续指令继续推进。
//   flush_flag_o ：清空 ID/EX 中已经进入执行级前方的错误或未就绪指令。
//
// 设计原则：
//   1. 普通 ALU 结果依赖优先交给 forwarding 解决，这里不额外停顿。
//   2. load-use 依赖在数据尚不可转发时停顿并 flush，避免消费者拿到旧值。
//   3. RV32M 乘除法等多周期执行由 ex_busy_i/ex_done_i 控制前端冻结。
//   4. 对 cache-hit load 后接移位指令做一次有选择的停顿，用一拍换取
//      MEM2 -> forwarding -> barrel shifter 关键路径的时序余量。
// ============================================================================
module Hazard_detection_unit (
    input  wire [31:0] id_inst_i,
    input  wire [4:0]  id_rs1_addr_i,
    input  wire [4:0]  id_rs2_addr_i,

    input  wire        id_use_rs1_i,
    input  wire        id_use_rs2_i,
    input wire ex_done_i,
    input  wire [31:0] ex_inst_i,
    input  wire [31:0] mem1_inst_i,
    input  wire        mem1_load_cache_hit_i,
    input  wire [31:0] mem2_inst_i,

    input  wire        mem2_is_slow_load_i,

    input  wire        ex_busy_i,

    (* max_fanout = 4 *) output reg hold_flag_o,
    (* max_fanout = 4 *) output reg flush_flag_o
);
    wire [6:0] id_opcode        = id_inst_i[6:0];
    wire [2:0] id_func3         = id_inst_i[14:12];
    wire [6:0] id_func7         = id_inst_i[31:25];

    wire [6:0] ex_opcode        = ex_inst_i[6:0];
    wire [4:0] ex_rd            = ex_inst_i[11:7];

    wire [6:0] mem1_opcode      = mem1_inst_i[6:0];
    wire [4:0] mem1_rd          = mem1_inst_i[11:7];


    wire [6:0] mem2_opcode      = mem2_inst_i[6:0];
    wire [4:0] mem2_rd          = mem2_inst_i[11:7];

    // ================================================================
    // 目的寄存器写回属性判断
    // ----------------------------------------------------------------
    // 这里只从指令类型粗略判断是否会写 rd：
    //   - S 型 store 不写 rd
    //   - B 型 branch 不写 rd
    //   - x0 永远不能作为真实写回目的寄存器
    //
    // 对 JAL/JALR/LUI/AUIPC/ALU/LOAD 等会写 rd 的指令，后续再结合
    // ID 阶段实际使用的 rs1/rs2 判断是否存在 RAW 依赖。
    // ================================================================

    wire ex_writes_rd =
        (ex_rd != 5'b0) &&
        (ex_opcode != `INST_TYPE_S) &&
        (ex_opcode != `INST_TYPE_B);

    wire mem1_writes_rd =
        (mem1_rd != 5'b0) &&
        (mem1_opcode != `INST_TYPE_S) &&
        (mem1_opcode != `INST_TYPE_B);


    wire mem2_writes_rd =
        (mem2_rd != 5'b0) &&
        (mem2_opcode != `INST_TYPE_S) &&
        (mem2_opcode != `INST_TYPE_B);

    // ================================================================
    // 普通 RAW 依赖匹配
    // ----------------------------------------------------------------
    // dep_match 只表示“当前 ID 指令读取了某个尚在流水线中的 rd”。
    // 注意：命中 dep_match 不一定需要停顿。普通 ALU/JAL/LUI 等结果通常
    // 可以由 forwarding 网络解决；真正需要本模块停顿的是后面的 load-use、
    // 慢速 load、以及多周期执行单元场景。
    // ================================================================

    wire ex_dep_match =
        ex_writes_rd &&
        ((id_use_rs1_i && (ex_rd == id_rs1_addr_i)) ||
         (id_use_rs2_i && (ex_rd == id_rs2_addr_i)));

    wire mem1_dep_match =
        mem1_writes_rd &&
        ((id_use_rs1_i && (mem1_rd == id_rs1_addr_i)) ||
         (id_use_rs2_i && (mem1_rd == id_rs2_addr_i)));


    wire mem2_dep_match =
        mem2_writes_rd &&
        ((id_use_rs1_i && (mem2_rd == id_rs1_addr_i)) ||
         (id_use_rs2_i && (mem2_rd == id_rs2_addr_i)));

    // ================================================================
    // load-use 依赖检测
    // ----------------------------------------------------------------
    // EX 阶段 load：
    //   load 的数据至少要到后续访存阶段才产生，紧跟的消费者不能直接进入 EX，
    //   因此需要 hold 前端并 flush 当前 ID/EX。
    //
    // MEM1 阶段 load miss：
    //   cache miss 或 MMIO/慢速路径的数据仍未准备好，继续停顿。
    //
    // MEM2 慢速 load：
    //   即使指令已经推进到 MEM2，只要外部标记为 slow load，消费者仍然
    //   不能放行，避免从转发网络读到无效数据。
    // ================================================================

    wire ex_load_dep =
        (ex_opcode == `INST_TYPE_L) &&
        ex_dep_match;

    wire mem1_load_dep =
        (mem1_opcode == `INST_TYPE_L) &&
        mem1_dep_match &&
        !mem1_load_cache_hit_i;


    wire mem2_slow_load_dep =
        mem2_is_slow_load_i &&
        (mem2_opcode == `INST_TYPE_L) &&
        mem2_dep_match;

    // ================================================================
    // cache-hit load 后接移位指令的定向停顿
    // ----------------------------------------------------------------
    // 一般情况下，cache-hit load 的数据可以在 MEM2 通过 forwarding 直接
    // 送给下一条消费者，不需要额外停顿。
    //
    // 但当消费者是移位指令时，组合路径会变成：
    //   MEM2 load data -> forwarding 选择 -> barrel shifter -> EX 结果
    //
    // 这条路径比普通 ALU 消费者更长，容易成为时序关键路径。这里仅对
    // “cache-hit load + 紧邻移位消费者” 插入一拍停顿：
    //   - miss 场景仍由 mem1_load_dep / mem2_slow_load_dep 处理；
    //   - 非移位消费者仍保持原有 forwarding 行为，不额外增加 CPI；
    //   - 移位立即数只实际使用 rs1，移位寄存器形式还要检查 rs2。
    // ================================================================
    wire id_is_shift_imm =
        (id_opcode == `INST_TYPE_I) &&
        (((id_func3 == `INST_SLLI) && (id_func7 == `INST_FUNC7_R)) ||
         ((id_func3 == `INST_SRI)  &&
          ((id_func7 == `INST_FUNC7_R) || (id_func7 == `INST_FUNC7_SUB))));

    wire id_is_shift_reg =
        (id_opcode == `INST_TYPE_R_M) &&
        (((id_func3 == `INST_SLL) && (id_func7 == `INST_FUNC7_R)) ||
         ((id_func3 == `INST_SR)  &&
          ((id_func7 == `INST_FUNC7_R) || (id_func7 == `INST_FUNC7_SUB))));

    wire id_is_shift = id_is_shift_imm || id_is_shift_reg;

    wire mem1_load_shift_dep =
        mem1_load_cache_hit_i &&
        (mem1_opcode == `INST_TYPE_L) &&
        id_is_shift &&
        (mem1_rd != 5'b0) &&
        (((mem1_rd == id_rs1_addr_i)) ||
         (id_is_shift_reg && (mem1_rd == id_rs2_addr_i)));

    // ================================================================
    // 最终 hold / flush 生成
    // ----------------------------------------------------------------
    // hold_flag_o 和 flush_flag_o 在本组合块中独立置位，不使用 else-if。
    // 这样多个冒险条件同周期出现时，任意一个需要停顿的条件都能生效。
    //
    // 各条件含义：
    //   ex_busy_i：
    //     多周期 EX 单元仍在工作，前端必须保持，但当前 ID/EX 内容不需要
    //     因 busy 本身被清空。
    //
    //   ex_done_i：
    //     多周期结果完成时，前端仍保持一拍，并 flush 掉等待期间可能进入
    //     ID/EX 的占位指令，保证后续重新以正确结果继续执行。
    //
    //   ex_load_dep / mem1_load_dep / mem2_slow_load_dep：
    //     数据尚不可安全转发，必须同时 hold 和 flush，插入气泡等待数据。
    //
    //   mem1_load_shift_dep：
    //     数据可转发但移位消费者路径过长，主动插入一拍气泡改善时序。
    // ================================================================
    always @(*) begin
        hold_flag_o       = 1'b0;
        flush_flag_o      = 1'b0;

        if (ex_busy_i == 1'b1) begin
            hold_flag_o = 1'b1;
        end
        if (ex_done_i == 1'b1) begin
            hold_flag_o  = 1'b1;
            flush_flag_o = 1'b1;
        end
        if (ex_load_dep) begin
            hold_flag_o  = 1'b1;
            flush_flag_o = 1'b1;
        end

        if (mem1_load_dep) begin
            hold_flag_o  = 1'b1;
            flush_flag_o = 1'b1;
        end

        if (mem1_load_shift_dep) begin
            hold_flag_o  = 1'b1;
            flush_flag_o = 1'b1;
        end

        if (mem2_slow_load_dep) begin
            hold_flag_o  = 1'b1;
            flush_flag_o = 1'b1;
        end


    end
endmodule
