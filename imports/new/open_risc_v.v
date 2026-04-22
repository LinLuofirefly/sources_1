
`include "defines.v"

module open_risc_v (
    input  wire        clk,                // 时钟信号
    input  wire        rst_n,              // 复位信号 (低电平有�?
    input  wire [31:0] inst_i,             // instruction from external ROM
    input  wire [31:0] ram_data_i,         // data from external RAM
    output wire [31:0] pc_reg_pc_o,        // 输出给外�?ROM 的取指地址
    output wire        mem_rd_reg_o,       // 输出给外�?RAM 的读使能
    output wire [31:0] mem_rd_addr_o,      // load address to external RAM
    output wire [3:0]  w_en,               // 输出给外�?RAM 的写使能 (掩码)
    output wire [31:0] w_addr_i,           // 输出给外�?RAM 的写地址
    output wire [31:0] w_data_i            // 输出给外�?RAM 的写数据
);

    // =================================================================
    // 0. 全局控制信号
    // =================================================================

    wire rst = rst_n;                      // 统一复位信号命名

    // --- CTRL (跳转控制�? 输出 ---

    wire [31:0] ctrl_jump_addr_o;          // 跳转目标地址

    wire        ctrl_jump_en_o;            // 跳转使能

    wire        ctrl_flush_ifid_o;         // 冲刷信号: IF/ID (寄存化)

    wire        ctrl_flush_idex_o;         // 冲刷信号: ID/EX (寄存化)

    wire        ctrl_flush_exmem1_o;       // 冲刷信号: EX/MEM1 (延迟一拍)

    // --- HDU (冒险检测单�? 输出 ---

    wire        hdu_hold_flag_o;           // 冻结信号: 冻结 PC �?IF/ID

    wire        hdu_flush_flag_o;          // 冲刷信号: 清空 ID/EX (�?NOP)

    // =================================================================
    // 1. IF �?�?ID �? 级间线网
    // =================================================================

    wire [31:0] if_id_inst_addr_o;         // IF/ID 输出的指令地址

    wire [31:0] if_id_inst_o;              // IF/ID 输出的指�?
    // =================================================================
    // 2. ID 级输出线�?    // =================================================================

    wire [4:0]  id_rs1_addr_o;             // ID 输出: rs1 读地址

    wire [4:0]  id_rs2_addr_o;             // ID 输出: rs2 读地址

    wire [31:0] id_inst_o;                 // ID 输出: 透传指令

    wire [31:0] id_inst_addr_o;            // ID 输出: 透传 PC 地址

    wire [31:0] id_op1_o;                  // ID 输出: ALU 操作�?1

    wire [31:0] id_op2_o;                  // ID 输出: ALU 操作?2

    wire [4:0]  id_rd_addr_o;            

 
    wire        id_reg_wen;                
    wire [31:0] id_base_addr_o;            
    wire [31:0] id_addr_offset_o;          
    wire        data_read_en;              

    // =================================================================
    // 3. 寄存器堆读出数据
    // =================================================================

    wire [31:0] regs_reg1_rdata_o;         // Regfile 读端�?1 数据

    wire [31:0] regs_reg2_rdata_o;         // Regfile 读端�?2 数据

    // --- WB 写回�?�?Regfile 写端�?---

    wire [4:0]  wb_rd_addr_o;              // WB 输出: 写回地址

    wire [31:0] wb_rd_data_o;              // WB 输出: 写回数据

    wire        wb_rd_wen_o;               // WB 输出: 写使�?
    // =================================================================
    // 4. ID/EX 级间线网
    // =================================================================

    wire [31:0] id_ex_inst_o;              // ID/EX 输出: 指令

    wire [31:0] id_ex_inst_addr_o;         // ID/EX 输出: PC 地址

    wire [31:0] id_ex_op1_o;               // ID/EX 输出: 操作�?1

    wire [31:0] id_ex_op2_o;               // ID/EX 输出: 操作�?2

    wire [4:0]  id_ex_rd_addr_o;           // ID/EX 输出: 目标寄存器地址

    wire        id_ex_reg_wen;             // ID/EX 输出: 写使�?
    wire [31:0] id_ex_base_addr_o;         // ID/EX 输出: 访存基地址

    wire [31:0] id_ex_addr_offset_o;       // ID/EX 输出: 地址偏移�?
    // =================================================================
    // 5. EX 级输出线�?    // =================================================================

    wire [4:0]  ex_rd_addr_o;              // EX 输出: 写回地址

    wire [31:0] ex_rd_data_o;              // EX 输出: ALU 结果

    wire        ex_rd_wen_o;               // EX 输出: 写使�?
    wire [3:0]  ex_wd_reg_o;               // EX 输出: Store 写掩�?
    wire [31:0] ex_wd_addr_o;              // EX 输出: Store 写地址

    wire [31:0] ex_wd_data_o;              // EX 输出: Store 写数�?
    wire        ex_is_load_o;              // EX 输出: Load 标记

    wire [31:0] ex_inst_o;                 // EX 输出: 透传指令

    wire [31:0] ex_jump_addr_o;            // EX 输出: 跳转地址

    wire        ex_jump_en_o;              // EX 输出: 跳转使能

    wire [31:0] ex_rd_mem_addr_o;          // EX 输出: Load 读地址

    // =================================================================
    // 5b. 前递单元输出线�?    // =================================================================

    wire [31:0] fwd_op1_o;                 // 前递后的操作数 1

    wire [31:0] fwd_op2_o;                 // 前递后的操作数 2

    wire [31:0] fwd_base_addr_o;           // 前递后的访存基地址

    wire [31:0] fwd_addr_offset_o;         // 透传的地址偏移�?
    // =================================================================
    // 6. EX/MEM1 级间线网
    // =================================================================

    wire [4:0]  ex_mem_pipe_rd_addr_o;     // EX/MEM1 输出: 写回地址

    wire [31:0] ex_mem_rd_data_o;          // EX/MEM1 输出: ALU 结果

    wire        ex_mem_rd_wen_o;           // EX/MEM1 输出: 写使�?
    wire [3:0]  ex_mem_wd_reg_o;           // EX/MEM1 输出: Store 写掩�?
    wire [31:0] ex_mem_wd_addr_o;          // EX/MEM1 输出: Store 写地址

    wire [31:0] ex_mem_wd_data_o;          // EX/MEM1 输出: Store 写数�?
    wire        ex_mem_is_load_o;          // EX/MEM1 输出: Load 标记

    wire [31:0] ex_mem_inst_o;             // EX/MEM1 输出: 指令

    wire [31:0] ex_mem_mem_rd_addr_o;      // EX/MEM1 输出: Load 读地址

    // =================================================================
    // 7. MEM1 级输出线�?    // =================================================================

    wire [4:0]  mem_out_rd_addr_o;         // MEM1 输出: 写回地址

    wire [31:0] mem_out_rd_data_o;         // MEM1 输出: ALU 结果

    wire        mem_out_rd_wen_o;          // MEM1 输出: 写使�?
    wire [31:0] mem_inst_o;                // MEM1 输出: 指令

    wire [31:0] mem_out_mem_rd_addr_o;     // MEM1 输出: Load 读地址

    wire        mem_out_is_load_o;         // MEM1 输出: Load 标记

    // =================================================================
    // 8. MEM1/MEM2 级间线网
    // =================================================================

    wire [4:0]  mem1_mem2_rd_addr_o;       // MEM1/MEM2 输出: 写回地址

    wire [31:0] mem1_mem2_rd_data_o;       // MEM1/MEM2 输出: ALU 结果

    wire        mem1_mem2_rd_wen_o;        // MEM1/MEM2 输出: 写使�?
    wire [31:0] mem1_mem2_inst_o;          // MEM1/MEM2 输出: 指令

    wire [31:0] mem1_mem2_mem_rd_addr_o;   // MEM1/MEM2 输出: Load 读地址

    wire        mem1_mem2_is_load_o;       // MEM1/MEM2 输出: Load 标记

    // =================================================================
    // 8b. MEM2 对齐级线网 (新增 1 拍)
    // =================================================================

    wire [4:0]  mem2_align_rd_addr_o;
    wire [31:0] mem2_align_rd_data_o;
    wire        mem2_align_rd_wen_o;
    wire [31:0] mem2_align_inst_o;
    wire [31:0] mem2_align_mem_rd_addr_o;
    wire        mem2_align_is_load_o;

    // =================================================================
    // 9. MEM2 级输出线�?    // =================================================================

    wire [31:0] mem2_inst_o;               // MEM2 输出: 指令

    wire [4:0]  mem2_rd_addr_o;            // MEM2 输出: 写回地址

    wire [31:0] mem2_rd_data_o;            // MEM2 输出: 写回数据 (�?Load 对齐)

    wire        mem2_rd_wen_o;             // MEM2 输出: 写使�?
    // =================================================================
    // 10. MEM2/WB 级间线网
    // =================================================================

    wire [4:0]  mem_wb_rd_addr_o;          // MEM2/WB 输出: 写回地址

    wire [31:0] mem_wb_rd_data_o;          // MEM2/WB 输出: 写回数据

    wire        mem_wb_rd_wen_o;           // MEM2/WB 输出: 写使�?
    wire [31:0] mem_wb_inst_o;             // MEM2/WB 输出: 指令

    // =================================================================
    // 顶层外部 RAM 接口连线
    // =================================================================
    assign mem_rd_reg_o  = ex_mem_is_load_o;       // Load 使能 �?外部 RAM
    assign mem_rd_addr_o = ex_mem_mem_rd_addr_o;   // Load read address to external RAM
 

    // *************************************************************************************************
    // 模块例化 (Module Instantiations)
    // *****************************************************************

    // -----------------------------------------------------------------
    // 1. PC 寄存�?    //    hold: Load-Use 冒险时冻�?PC
    //    jump: 跳转时加载目标地址
    // -----------------------------------------------------------------
    pc_reg pc_reg_inst (
        .clk         (clk),
        .rst         (rst),
        .jump_en     (ctrl_jump_en_o),
        .jump_addr_i (ctrl_jump_addr_o),
        .hold_flag_i (hdu_hold_flag_o),
        .pc_o        (pc_reg_pc_o)
    );

    // -----------------------------------------------------------------
    // 2. IF/ID 流水线寄存器 (�?Skid Buffer)
    //    hold: Load-Use 冒险时冻�?    //    flush: 跳转时冲�?(插入 NOP)
    // -----------------------------------------------------------------
    if_id if_id_inst (
        .clk          (clk),
        .rst          (rst),
        .inst_i       (inst_i),
        .inst_addr_i  (pc_reg_pc_o),
        .inst_addr_o  (if_id_inst_addr_o),
        .inst_o       (if_id_inst_o),
        .hold_flag_i  (hdu_hold_flag_o),
        .flush_flag_i (ctrl_flush_ifid_o)
    );

    // -----------------------------------------------------------------
    // 3. 通用寄存器堆
    //    读端�? 连接 ID 级的 rs1/rs2
    //    写端�? 连接 WB 级的写回信号
    // -----------------------------------------------------------------
    regs regs_inst (
        .clk          (clk),
        .reg1_raddr_i (id_rs1_addr_o),
        .reg2_raddr_i (id_rs2_addr_o),
        .reg1_rdata_o (regs_reg1_rdata_o),
        .reg2_rdata_o (regs_reg2_rdata_o),
        .reg_wen      (wb_rd_wen_o),
        .reg_waddr_i  (wb_rd_addr_o),
        .reg_wdata_i  (wb_rd_data_o)
    );

    // -----------------------------------------------------------------
    // 4. 译码模块 (ID)
    // -----------------------------------------------------------------
    id id_inst (
        .inst_i        (if_id_inst_o),
        .inst_addr_i   (if_id_inst_addr_o),
        .rs1_data_i    (regs_reg1_rdata_o),
        .rs2_data_i    (regs_reg2_rdata_o),
        .rs1_addr_o    (id_rs1_addr_o),
        .rs2_addr_o    (id_rs2_addr_o),
        .inst_o        (id_inst_o),
        .inst_addr_o   (id_inst_addr_o),
        .op1_o         (id_op1_o),
        .op2_o         (id_op2_o),
        .rd_addr_o     (id_rd_addr_o),
        .reg_wen       (id_reg_wen),
        .base_addr_o   (id_base_addr_o),
        .addr_offset_o (id_addr_offset_o),
        .mem_rd_reg_o  (data_read_en)
    );

    // -----------------------------------------------------------------
    // 5. ID/EX 流水线寄存器
    //    hold: 不冻�?(恒为 0)
    //    flush: Load-Use 或跳转时清空
    // -----------------------------------------------------------------
    id_ex id_ex_inst (
        .clk           (clk),
        .rst           (rst),
        .hold_flag_i   (1'b0),
        .flush_flag_i  (hdu_flush_flag_o | ctrl_flush_idex_o),
        .inst_i        (id_inst_o),
        .inst_addr_i   (id_inst_addr_o),
        .op1_i         (id_op1_o),
        .op2_i         (id_op2_o),
        .rd_addr_i     (id_rd_addr_o),
        .reg_wen_i     (id_reg_wen),
        .base_addr_i   (id_base_addr_o),
        .addr_offset_i (id_addr_offset_o),
        .inst_o        (id_ex_inst_o),
        .inst_addr_o   (id_ex_inst_addr_o),
        .op1_o         (id_ex_op1_o),
        .op2_o         (id_ex_op2_o),
        .rd_addr_o     (id_ex_rd_addr_o),
        .reg_wen_o     (id_ex_reg_wen),
        .base_addr_o   (id_ex_base_addr_o),
        .addr_offset_o (id_ex_addr_offset_o)
    );

    // -----------------------------------------------------------------
    // 6a. 前递单�?(Forwarding Unit)
    //     三条前递路�? EX/MEM1→EX, MEM1/MEM2→EX, MEM2/WB→EX
    // -----------------------------------------------------------------
    forwarding forwarding_inst (
        .id_ex_inst_i        (id_ex_inst_o),
        .id_ex_op1_i         (id_ex_op1_o),
        .id_ex_op2_i         (id_ex_op2_o),
        .id_ex_base_addr_i   (id_ex_base_addr_o),
        .id_ex_addr_offset_i (id_ex_addr_offset_o),
        .ex_mem_rd_addr_i    (ex_mem_pipe_rd_addr_o),
        .ex_mem_rd_data_i    (ex_mem_rd_data_o),
        .ex_mem_rd_wen_i     (ex_mem_rd_wen_o),
        .ex_mem_is_load_i    (ex_mem_is_load_o),
        .mem1_mem2_rd_addr_i (mem1_mem2_rd_addr_o),
        .mem1_mem2_rd_data_i (mem1_mem2_rd_data_o),
        .mem1_mem2_rd_wen_i  (mem1_mem2_rd_wen_o),
        .mem2_rd_addr_i      (mem2_rd_addr_o),
        .mem2_rd_data_i      (mem2_rd_data_o),
        .mem2_rd_wen_i       (mem2_rd_wen_o),
        .mem_wb_rd_addr_i    (mem_wb_rd_addr_o),
        .mem_wb_rd_data_i    (mem_wb_rd_data_o),
        .mem_wb_rd_wen_i     (mem_wb_rd_wen_o),
        .fwd_op1_o           (fwd_op1_o),
        .fwd_op2_o           (fwd_op2_o),
        .fwd_base_addr_o     (fwd_base_addr_o),
        .fwd_addr_offset_o   (fwd_addr_offset_o)
    );

    // -----------------------------------------------------------------
    // 6b. 冒险检测单�?(Hazard Detection Unit)
    //     检�?Load-Use 冒险: 冻结 PC/IF_ID，冲�?ID/EX
    // -----------------------------------------------------------------
    Hazard_detection_unit hdu_inst (
        .id_inst_i    (if_id_inst_o),
        .ex_inst_i    (id_ex_inst_o),
        .mem1_inst_i  (mem_inst_o),
        .mem1_mem2_inst_i (mem1_mem2_inst_o),
        .mem2a_inst_i (mem2_align_inst_o),
        .mem2_inst_i  (mem2_inst_o),
        .hold_flag_o  (hdu_hold_flag_o),
        .flush_flag_o (hdu_flush_flag_o)
    );

    // -----------------------------------------------------------------
    // 6c. 执行模块 (EX)
    //     操作数来自前递单�?(解决 RAW 数据冒险)
    // -----------------------------------------------------------------
    ex ex_inst (
        .inst_i        (id_ex_inst_o),
        .inst_addr_i   (id_ex_inst_addr_o),
        .op1_i         (fwd_op1_o),
        .op2_i         (fwd_op2_o),
        .rd_addr_i     (id_ex_rd_addr_o),
        .rd_wen_i      (id_ex_reg_wen),
        .base_addr_i   (fwd_base_addr_o),
        .addr_offset_i (fwd_addr_offset_o),
        .rd_addr_o     (ex_rd_addr_o),
        .rd_wen_o      (ex_rd_wen_o),
        .rd_data_o     (ex_rd_data_o),
        .jump_addr_o   (ex_jump_addr_o),
        .jump_en_o     (ex_jump_en_o),
        .mem_wd_reg_o  (ex_wd_reg_o),
        .mem_wd_addr_o (ex_wd_addr_o),
        .mem_wd_data_o (ex_wd_data_o),
        .mem_rd_addr_o (ex_rd_mem_addr_o),
        .is_load_o     (ex_is_load_o),
        .inst_o        (ex_inst_o)
    );

    // -----------------------------------------------------------------
    // 7. 中央控制�?(CTRL)
    //    检测跳转，输出 2 拍冲刷信�?    // -----------------------------------------------------------------
    ctrl ctrl_inst (
        .clk          (clk),
        .rst          (rst),
        .jump_addr_i  (ex_jump_addr_o),
        .jump_en_i    (ex_jump_en_o),
        .jump_en_o    (ctrl_jump_en_o),
        .jump_addr_o  (ctrl_jump_addr_o),
        .flush_ifid_o (ctrl_flush_ifid_o),
        .flush_idex_o (ctrl_flush_idex_o),
        .flush_exmem1_o(ctrl_flush_exmem1_o),
        .flush_flag_o ()
    );

    // -----------------------------------------------------------------
    // 8. EX/MEM1 流水线寄存器
    // -----------------------------------------------------------------
    ex_mem1 ex_mem_inst (
        .clk           (clk),
        .rst           (rst),
        .hold_flag_i   (1'b0),
        .flush_flag_i  (ctrl_flush_exmem1_o),
        .inst_i        (ex_inst_o),
        .rd_addr_i     (ex_rd_addr_o),
        .rd_data_i     (ex_rd_data_o),
        .rd_wen_i      (ex_rd_wen_o),
        .mem_wd_reg_i  (ex_wd_reg_o),
        .mem_wd_addr_i (ex_wd_addr_o),
        .mem_wd_data_i (ex_wd_data_o),
        .mem_rd_addr_i (ex_rd_mem_addr_o),
        .is_load_i     (ex_is_load_o),
        .rd_addr_o     (ex_mem_pipe_rd_addr_o),
        .rd_data_o     (ex_mem_rd_data_o),
        .rd_wen_o      (ex_mem_rd_wen_o),
        .mem_wd_reg_o  (ex_mem_wd_reg_o),
        .mem_wd_addr_o (ex_mem_wd_addr_o),
        .mem_wd_data_o (ex_mem_wd_data_o),
        .mem_rd_addr_o (ex_mem_mem_rd_addr_o),
        .is_load_o     (ex_mem_is_load_o),
        .inst_o        (ex_mem_inst_o)
    );

    // -----------------------------------------------------------------
    // 9. 第一访存�?(MEM1)
    //    发起 Store 写操作，透传控制信号�?MEM1/MEM2
    // -----------------------------------------------------------------
    mem1 mem_inst (
        .inst_i        (ex_mem_inst_o),
        .rd_addr_i     (ex_mem_pipe_rd_addr_o),
        .rd_data_i     (ex_mem_rd_data_o),
        .rd_wen_i      (ex_mem_rd_wen_o),
        .mem_rd_addr_i (ex_mem_mem_rd_addr_o),
        .mem_wd_reg_i  (ex_mem_wd_reg_o),
        .mem_wd_addr_i (ex_mem_wd_addr_o),
        .mem_wd_data_i (ex_mem_wd_data_o),
        .is_load_i     (ex_mem_is_load_o),
        .rd_addr_o     (mem_out_rd_addr_o),
        .rd_data_o     (mem_out_rd_data_o),
        .rd_wen_o      (mem_out_rd_wen_o),
        .mem_rd_addr_o (mem_out_mem_rd_addr_o),
        .mem_wd_reg_o  (w_en),
        .mem_wd_addr_o (w_addr_i),
        .mem_wd_data_o (w_data_i),
        .inst_o        (mem_inst_o),
        .is_load_o     (mem_out_is_load_o)
    );

    // -----------------------------------------------------------------
    // 10. MEM1/MEM2 流水线寄存器
    //     将控制信号延�?1 拍，�?RAM 同步读延迟对�?    // -----------------------------------------------------------------
    mem1_mem2 mem1_mem2_inst (
        .clk           (clk),
        .rst           (rst),
        .hold_flag_i   (1'b0),
        .flush_flag_i  (1'b0),
        .inst_i        (mem_inst_o),
        .rd_addr_i     (mem_out_rd_addr_o),
        .rd_data_i     (mem_out_rd_data_o),
        .rd_wen_i      (mem_out_rd_wen_o),
        .mem_rd_addr_i (mem_out_mem_rd_addr_o),
        .is_load_i     (mem_out_is_load_o),
        .rd_addr_o     (mem1_mem2_rd_addr_o),
        .rd_data_o     (mem1_mem2_rd_data_o),
        .rd_wen_o      (mem1_mem2_rd_wen_o),
        .mem_rd_addr_o (mem1_mem2_mem_rd_addr_o),
        .is_load_o     (mem1_mem2_is_load_o),
        .inst_o        (mem1_mem2_inst_o)
    );

    // -----------------------------------------------------------------
    // 10b. MEM2 对齐级寄存器 (新增)
    //      让 load 控制与延迟后的 RAM 返回数据同拍进入 MEM2
    // -----------------------------------------------------------------
    mem1_mem2 mem2_align_inst (
        .clk           (clk),
        .rst           (rst),
        .hold_flag_i   (1'b0),
        .flush_flag_i  (1'b0),
        .inst_i        (mem1_mem2_inst_o),
        .rd_addr_i     (mem1_mem2_rd_addr_o),
        .rd_data_i     (mem1_mem2_rd_data_o),
        .rd_wen_i      (mem1_mem2_rd_wen_o),
        .mem_rd_addr_i (mem1_mem2_mem_rd_addr_o),
        .is_load_i     (mem1_mem2_is_load_o),
        .rd_addr_o     (mem2_align_rd_addr_o),
        .rd_data_o     (mem2_align_rd_data_o),
        .rd_wen_o      (mem2_align_rd_wen_o),
        .mem_rd_addr_o (mem2_align_mem_rd_addr_o),
        .is_load_o     (mem2_align_is_load_o),
        .inst_o        (mem2_align_inst_o)
    );

    // -----------------------------------------------------------------
    // 11. 第二访存�?(MEM2)
    //     接收 RAM 读数据，完成 Load 数据对齐/扩展
    // -----------------------------------------------------------------
    mem2 mem2_inst (
        .inst_i        (mem2_align_inst_o),
        .rd_addr_i     (mem2_align_rd_addr_o),
        .rd_data_i     (mem2_align_rd_data_o),
        .rd_wen_i      (mem2_align_rd_wen_o),
        .mem_rd_addr_i (mem2_align_mem_rd_addr_o),
        .is_load_i     (mem2_align_is_load_o),
        .mem_rd_data_i (ram_data_i),
        .rd_addr_o     (mem2_rd_addr_o),
        .rd_data_o     (mem2_rd_data_o),
        .rd_wen_o      (mem2_rd_wen_o),
        .inst_o        (mem2_inst_o)
    );

    // -----------------------------------------------------------------
    // 12. MEM2/WB 流水线寄存器
    // -----------------------------------------------------------------
    mem2_wb mem_wb_inst (
        .clk         (clk),
        .rst         (rst),
        .hold_flag_i (1'b0),
        .inst_i      (mem2_inst_o),
        .rd_addr_i   (mem2_rd_addr_o),
        .rd_data_i   (mem2_rd_data_o),
        .rd_wen_i    (mem2_rd_wen_o),
        .rd_addr_o   (mem_wb_rd_addr_o),
        .rd_data_o   (mem_wb_rd_data_o),
        .rd_wen_o    (mem_wb_rd_wen_o),
        .inst_o      (mem_wb_inst_o)
    );

    // -----------------------------------------------------------------
    // 13. 写回模块 (WB)
    //     将最终数据写回寄存器�?    // -----------------------------------------------------------------
    wb wb_inst (
        .inst_i    (mem_wb_inst_o),
        .rd_addr_i (mem_wb_rd_addr_o),
        .rd_data_i (mem_wb_rd_data_o),
        .rd_wen_i  (mem_wb_rd_wen_o),
        .inst_o    (),                     // 悬空: WB 之后无下一�?        
        .rd_data_o (wb_rd_data_o),
        .rd_wen_o  (wb_rd_wen_o),
        .rd_addr_o (wb_rd_addr_o)
    );

endmodule





