`timescale 1ns / 1ps

// ============================================================================
// ID 阶段提前选择转发来源
// ----------------------------------------------------------------------------
// 本模块只产生 2-bit forwarding 选择码，不直接搬运 32-bit 数据。
// 这样可以把“比较 rd/rs”提前放在 ID 阶段，EX 阶段只做小 mux 选择，
// 缩短 EX 的 ALU、branch、JALR 数据路径。
//
// 转发优先级保持最新数据优先：
//   EX/MEM > MEM1/MEM2 > MEM/WB > 寄存器堆原值
// load 数据只有在已知可用时才允许被选中，避免消费者读到未完成的 load。
// ============================================================================
module early_forwarding_select (
    input  wire [4:0] id_rs1_addr_i,
    input  wire [4:0] id_rs2_addr_i,
    input  wire       id_use_rs1_i,
    input  wire       id_use_rs2_i,
    input  wire       id_use_base_addr_i,

    input  wire [4:0] ex_rd_addr_i,
    input  wire       ex_rd_wen_i,
    input  wire       ex_is_load_i,

    input  wire [4:0] mem1_rd_addr_i,
    input  wire       mem1_rd_wen_i,
    input  wire       mem1_is_load_i,
    input  wire       mem1_load_cache_hit_i,

    input  wire [4:0] mem2_rd_addr_i,
    input  wire       mem2_rd_wen_i,
    input  wire       mem2_is_slow_load_i,

    output wire [1:0] rs1_fwd_sel_o,
    output wire [1:0] rs2_fwd_sel_o
);

    // 2位紧凑编码让单bit的4选1转发器只包含4个数据输入和2个选择输入，
    // 有机会映射进一个LUT6；优先级仍保持 EX/MEM > MEM1/MEM2 > MEM/WB > REG。
    localparam [1:0] FWD_REG       = 2'd0;
    localparam [1:0] FWD_EX_MEM    = 2'd1;
    localparam [1:0] FWD_MEM1_MEM2 = 2'd2;
    localparam [1:0] FWD_MEM_WB    = 2'd3;

    // rs1 既可能作为普通操作数，也可能作为 load/store/JALR 的 base 地址。
    wire rs1_forward_allowed = id_use_rs1_i | id_use_base_addr_i;
    wire rs2_forward_allowed = id_use_rs2_i;

    // Current EX becomes EX/MEM for the consumer's next-cycle EX stage.
    // 当前 EX 的非 load 结果在消费者下一拍进入 EX 时会位于 EX/MEM。
    // load 结果此时尚未产生，不能从 EX/MEM 提前转发。
    wire rs1_match_ex =
        rs1_forward_allowed &&
        (id_rs1_addr_i != 5'b0) &&
        ex_rd_wen_i &&
        (ex_rd_addr_i == id_rs1_addr_i) &&
        !ex_is_load_i;

    wire rs2_match_ex =
        rs2_forward_allowed &&
        (id_rs2_addr_i != 5'b0) &&
        ex_rd_wen_i &&
        (ex_rd_addr_i == id_rs2_addr_i) &&
        !ex_is_load_i;

    // Current MEM1 becomes MEM1/MEM2, and only cache-hit loads are ready there.
    // 当前 MEM1 下一拍会成为 MEM1/MEM2。非 load 结果可用；
    // load 只有 cache-hit 时才可在该级提供给消费者。
    wire rs1_match_mem1 =
        rs1_forward_allowed &&
        (id_rs1_addr_i != 5'b0) &&
        mem1_rd_wen_i &&
        (mem1_rd_addr_i == id_rs1_addr_i) &&
        (!mem1_is_load_i || mem1_load_cache_hit_i);

    wire rs2_match_mem1 =
        rs2_forward_allowed &&
        (id_rs2_addr_i != 5'b0) &&
        mem1_rd_wen_i &&
        (mem1_rd_addr_i == id_rs2_addr_i) &&
        (!mem1_is_load_i || mem1_load_cache_hit_i);

    // Current MEM2 becomes MEM/WB for the consumer's next-cycle EX stage.
    // 当前 MEM2 下一拍会成为 MEM/WB。slow load 仍需等 WB/MMIO 数据，
    // 因此 slow load 不允许在这里被选择为转发来源。
    wire rs1_match_mem2 =
        rs1_forward_allowed &&
        (id_rs1_addr_i != 5'b0) &&
        mem2_rd_wen_i &&
        (mem2_rd_addr_i == id_rs1_addr_i) &&
        !mem2_is_slow_load_i;

    wire rs2_match_mem2 =
        rs2_forward_allowed &&
        (id_rs2_addr_i != 5'b0) &&
        mem2_rd_wen_i &&
        (mem2_rd_addr_i == id_rs2_addr_i) &&
        !mem2_is_slow_load_i;

    assign rs1_fwd_sel_o =
        rs1_match_ex   ? FWD_EX_MEM    :
        rs1_match_mem1 ? FWD_MEM1_MEM2 :
        rs1_match_mem2 ? FWD_MEM_WB    :
                         FWD_REG;

    assign rs2_fwd_sel_o =
        rs2_match_ex   ? FWD_EX_MEM    :
        rs2_match_mem1 ? FWD_MEM1_MEM2 :
        rs2_match_mem2 ? FWD_MEM_WB    :
                         FWD_REG;

endmodule
