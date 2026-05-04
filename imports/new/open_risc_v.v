
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
    wire        ctrl_redirect_hold_o;
    wire        ctrl_kill_ex_o;

    wire        ctrl_flush_ifid_o;         // 冲刷信号: IF/ID (寄存化)
    wire        ctrl_flush_idpipe_o;       // 冲刷信号: 新增 ID 级
    wire        ctrl_flush_idex_o;         // 冲刷信号: ID/EX (寄存化)

    wire        bp_pred_taken_o;
    wire        bp_pred_taken_accepted_o;
    wire [31:0] bp_pred_target_o;
    wire [5:0]  bp_pred_ghr_o;
    wire        bp_pred_flush_o;
    reg         bp_pred_flush_d1_r;
    wire [31:0] pc_jump_addr_o;
    wire        pc_jump_en_o;
    reg  [31:0] bp_fetch_pc_r;
    reg         bp_fetch_valid_r;
    reg         ctrl_flush_ifid_d1_r;

    // --- HDU (冒险检测单�? 输出 ---

    wire        hdu_hold_req_o;            // HDU 组合冻结请求
    wire        hdu_flush_req_o;           // HDU 组合冲刷请求
    reg         hdu_hold_flag_o;           // 打一拍后的冻结信号
    reg         hdu_flush_flag_o;          // 打一拍后的冲刷信号

    // =================================================================
    // 1. IF �?�?ID �? 级间线网
    // =================================================================

    wire [31:0] if_id_inst_addr_o;         // IF/ID 输出的指令地址

    wire [31:0] if_id_inst_o;              // IF/ID 输出的指�?
    wire        if_id_pred_taken_o;
    wire        if_id_raw_pred_taken_o;
    wire [31:0] if_id_pred_target_o;
    wire [5:0]  if_id_pred_ghr_o;
    wire        if_id_valid_o;
    wire        if_id_replaying_o;
    wire [6:0]  hdu_id_opcode = id_pipe_inst_o[6:0];
    wire [4:0]  hdu_id_rs1    = id_pipe_inst_o[19:15];
    wire [4:0]  hdu_id_rs2    = id_pipe_inst_o[24:20];
    wire        hdu_id_use_rs1_ex = (hdu_id_opcode == `INST_TYPE_R_M) ||
                                    (hdu_id_opcode == `INST_TYPE_I)   ||
                                    (hdu_id_opcode == `INST_TYPE_S)   ||
                                    (hdu_id_opcode == `INST_TYPE_B)   ||
                                    (hdu_id_opcode == `INST_TYPE_L)   ||
                                    (hdu_id_opcode == `INST_JALR);
    wire        hdu_id_use_rs2_ex = (hdu_id_opcode == `INST_TYPE_R_M) ||
                                    (hdu_id_opcode == `INST_TYPE_B);
    wire        hdu_id_use_rs2_store_data = (hdu_id_opcode == `INST_TYPE_S);
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
    wire [14:0] id_ctrl_flags_o;
    wire [31:0] id_pipe_inst_o;
    wire [31:0] id_pipe_inst_addr_o;
    wire [31:0] id_pipe_op1_o;
    wire [31:0] id_pipe_op2_o;
    wire        id_pipe_pred_taken_o;
    wire        id_pipe_raw_pred_taken_o;
    wire [31:0] id_pipe_pred_target_o;
    wire [5:0]  id_pipe_pred_ghr_o;
    wire [4:0]  id_pipe_rd_addr_o;
    wire        id_pipe_reg_wen_o;
    wire [31:0] id_pipe_base_addr_o;
    wire [31:0] id_pipe_addr_offset_o;
    wire [14:0] id_pipe_ctrl_flags_o;
    wire        issue_ready_o;
    wire        issue_fire_o;
    wire        issue_valid_o;
    wire        issue_can_go_ex_o;
    wire        front_hold_o;
    wire        ifid_flush_now;
    wire        idpipe_flush_now;
    wire        if_id_consume_i;
    wire        issue_load_input;
    wire        id_issue_valid_i;
    wire        ifetch_req_fire;
    wire [31:0] issue_in_op1_o;
    wire [31:0] issue_in_op2_o;
    wire [31:0] issue_in_base_addr_o;
    wire [31:0] issue_in_addr_offset_o;
    wire [31:0] issue_emit_op1_o;
    wire [31:0] issue_emit_op2_o;
    wire [31:0] issue_emit_base_addr_o;
    wire [31:0] issue_emit_addr_offset_o;
    wire [6:0]  bp_if_opcode = inst_i[6:0];
    wire [2:0]  bp_if_func3  = inst_i[14:12];
    wire [4:0]  bp_if_rd     = inst_i[11:7];
    wire [4:0]  bp_if_rs1    = inst_i[19:15];
    wire        bp_if_rd_is_link = (bp_if_rd == 5'd1) || (bp_if_rd == 5'd5);
    wire        bp_if_rs1_is_link = (bp_if_rs1 == 5'd1) || (bp_if_rs1 == 5'd5);
    wire        bp_if_is_ret_like = (bp_if_opcode == `INST_JALR) &&
                                    (bp_if_func3 == 3'b000) &&
                                    bp_if_rs1_is_link &&
                                    (!bp_if_rd_is_link || (bp_if_rd != bp_if_rs1));
    wire        pending_x1_write;
    wire        pending_x2_write;
    wire        bp_ret_holdoff;
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
    wire        id_ex_pred_taken_o;
    wire        id_ex_raw_pred_taken_o;
    wire [31:0] id_ex_pred_target_o;
    wire [5:0]  id_ex_pred_ghr_o;

    wire [4:0]  id_ex_rd_addr_o;           // ID/EX 输出: 目标寄存器地址

    wire        id_ex_reg_wen;             // ID/EX 输出: 写使�?
    wire [31:0] id_ex_base_addr_o;         // ID/EX 输出: 访存基地址

    wire [31:0] id_ex_addr_offset_o;       // ID/EX 输出: 地址偏移�?
    wire [14:0] id_ex_ctrl_flags_o;
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
    wire        bp_update_en_o;
    wire [31:0] bp_update_pc_o;
    wire [5:0]  bp_update_ghr_o;
    wire        bp_ras_push_en_o;
    wire        bp_ras_pop_en_o;
    wire [31:0] bp_ras_push_addr_o;
    wire        bp_actual_taken_o;

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
    assign mem_rd_reg_o   = ex_mem_is_load_o;       // Load 使能 �?外部 RAM
    assign mem_rd_addr_o  = ex_mem_mem_rd_addr_o;   // Load read address to external RAM
    reg         recent_store_valid_r;
    reg  [31:0] recent_store_addr_r;
    reg  [31:0] recent_store_data_r;
    reg  [3:0]  recent_store_strb_r;
    wire        mem2_store_bypass_hit =
        mem2_align_is_load_o &&
        recent_store_valid_r &&
        (recent_store_strb_r != 4'b0000) &&
        (recent_store_addr_r[31:2] == mem2_align_mem_rd_addr_o[31:2]);
    wire [31:0] mem2_ram_data_i = {
        recent_store_strb_r[3] ? recent_store_data_r[31:24] : ram_data_i[31:24],
        recent_store_strb_r[2] ? recent_store_data_r[23:16] : ram_data_i[23:16],
        recent_store_strb_r[1] ? recent_store_data_r[15:8]  : ram_data_i[15:8],
        recent_store_strb_r[0] ? recent_store_data_r[7:0]   : ram_data_i[7:0]
    };
    wire bp_if_valid = bp_fetch_valid_r & ~ifid_flush_now;
    assign pending_x1_write =
        (issue_valid_o && id_pipe_reg_wen_o && (id_pipe_rd_addr_o == 5'd1)) ||
        (id_ex_reg_wen && (id_ex_rd_addr_o == 5'd1)) ||
        (ex_mem_rd_wen_o && (ex_mem_pipe_rd_addr_o == 5'd1)) ||
        (mem_out_rd_wen_o && (mem_out_rd_addr_o == 5'd1)) ||
        (mem1_mem2_rd_wen_o && (mem1_mem2_rd_addr_o == 5'd1)) ||
        (mem2_align_rd_wen_o && (mem2_align_rd_addr_o == 5'd1)) ||
        (mem2_rd_wen_o && (mem2_rd_addr_o == 5'd1)) ||
        (mem_wb_rd_wen_o && (mem_wb_rd_addr_o == 5'd1)) ||
        (wb_rd_wen_o && (wb_rd_addr_o == 5'd1));
    assign pending_x2_write =
        (issue_valid_o && id_pipe_reg_wen_o && (id_pipe_rd_addr_o == 5'd2)) ||
        (id_ex_reg_wen && (id_ex_rd_addr_o == 5'd2)) ||
        (ex_mem_rd_wen_o && (ex_mem_pipe_rd_addr_o == 5'd2)) ||
        (mem_out_rd_wen_o && (mem_out_rd_addr_o == 5'd2)) ||
        (mem1_mem2_rd_wen_o && (mem1_mem2_rd_addr_o == 5'd2)) ||
        (mem2_align_rd_wen_o && (mem2_align_rd_addr_o == 5'd2)) ||
        (mem2_rd_wen_o && (mem2_rd_addr_o == 5'd2)) ||
        (mem_wb_rd_wen_o && (mem_wb_rd_addr_o == 5'd2)) ||
        (wb_rd_wen_o && (wb_rd_addr_o == 5'd2));
    assign bp_ret_holdoff = 1'b0;
    assign issue_can_go_ex_o = (~issue_valid_o) | (~hdu_hold_req_o);
    assign ifid_flush_now = ctrl_flush_ifid_o |
                            bp_pred_flush_d1_r;
    assign idpipe_flush_now = ctrl_flush_idpipe_o;
    assign issue_load_input = if_id_valid_o &
                              issue_ready_o &
                              ~idpipe_flush_now;
    assign if_id_consume_i = issue_load_input;
    assign id_issue_valid_i = if_id_valid_o & ~idpipe_flush_now;
    assign front_hold_o = (~issue_ready_o) |
                          ctrl_redirect_hold_o |
                          ctrl_jump_en_o |
                          ifid_flush_now;
    assign ifetch_req_fire = pc_jump_en_o | (~front_hold_o);
    assign bp_pred_taken_accepted_o = bp_pred_taken_o &
                                  issue_load_input &
                                  ~if_id_replaying_o &
                                  ~ctrl_redirect_hold_o &
                                  ~ctrl_jump_en_o &
                                  ~ifid_flush_now &
                                  ~bp_ret_holdoff;
    assign pc_jump_en_o   = ctrl_jump_en_o | bp_pred_taken_accepted_o;
    assign pc_jump_addr_o = ctrl_jump_en_o ? ctrl_jump_addr_o : bp_pred_target_o;
    wire fetch_hold_keep =
    front_hold_o &&
    ~ctrl_redirect_hold_o &&
    ~ctrl_jump_en_o &&
    ~ifid_flush_now &&
    ~pc_jump_en_o;
    wire ifetch_new_req_fire =
    ifetch_req_fire &&
    (pc_jump_en_o ||
     (bp_fetch_valid_r == 1'b0) ||
     (pc_reg_pc_o != bp_fetch_pc_r));
    always @(posedge clk) begin
        if (rst == 1'b0) begin
            bp_fetch_pc_r            <= 32'h8000_0000;
            bp_fetch_valid_r         <= 1'b0;
            bp_pred_flush_d1_r       <= 1'b0;
            ctrl_flush_ifid_d1_r     <= 1'b0;
            recent_store_valid_r     <= 1'b0;
            recent_store_addr_r      <= 32'b0;
            recent_store_data_r      <= 32'b0;
            recent_store_strb_r      <= 4'b0;
            hdu_hold_flag_o          <= 1'b0;
            hdu_flush_flag_o         <= 1'b0;
        end else begin
            bp_fetch_pc_r            <= pc_reg_pc_o;
        if (fetch_hold_keep == 1'b1) begin
            bp_fetch_valid_r <= bp_fetch_valid_r;
        end else begin
            bp_fetch_valid_r <= ifetch_new_req_fire;
        end

        
            bp_pred_flush_d1_r       <= bp_pred_taken_accepted_o;
            ctrl_flush_ifid_d1_r     <= ctrl_flush_ifid_o;
            recent_store_valid_r     <= (w_en != 4'b0000);
            recent_store_addr_r      <= w_addr_i;
            recent_store_data_r      <= w_data_i;
            recent_store_strb_r      <= w_en;
            if (ctrl_redirect_hold_o || ctrl_jump_en_o || ctrl_flush_ifid_o) begin
                hdu_hold_flag_o      <= 1'b0;
                hdu_flush_flag_o     <= 1'b0;
            end else begin
                hdu_hold_flag_o      <= issue_valid_o & ~issue_can_go_ex_o;
                hdu_flush_flag_o     <= issue_valid_o & ~issue_can_go_ex_o;
            end
        end
    end



    // *************************************************************************************************
    // 模块例化 (Module Instantiations)
    // *****************************************************************

    // -----------------------------------------------------------------
    // 1. PC 寄存�?    //    hold: Load-Use 冒险时冻�?PC
    //    jump: 跳转时加载目标地址
    // -----------------------------------------------------------------
    branch_predictor branch_predictor_inst (
        .clk            (clk),
        .rst            (rst),
        .if_valid_i     (bp_if_valid),
        .if_inst_i      (inst_i),
        .if_pc_i        (bp_fetch_pc_r),
        .hold_flag_i    (front_hold_o),
        .flush_flag_i   (ctrl_jump_en_o | ifid_flush_now),
        .pred_taken_o   (bp_pred_taken_o),
        .pred_target_o  (bp_pred_target_o),
        .pred_ghr_o     (bp_pred_ghr_o),
        .pred_flush_o   (bp_pred_flush_o),
        .update_en_i    (bp_update_en_o),
        .update_pc_i    (bp_update_pc_o),
        .update_ghr_i   (bp_update_ghr_o),
        .ras_push_en_i  (bp_ras_push_en_o),
        .ras_pop_en_i   (bp_ras_pop_en_o),
        .ras_push_addr_i(bp_ras_push_addr_o),
        .actual_taken_i (bp_actual_taken_o)
    );

    pc_reg pc_reg_inst (
        .clk         (clk),
        .rst         (rst),
        .jump_en     (pc_jump_en_o),
        .jump_addr_i (pc_jump_addr_o),
        .hold_flag_i (front_hold_o),
        .pc_o        (pc_reg_pc_o)
    );

    // -----------------------------------------------------------------
    // 2. IF/ID 流水线寄存器 (�?Skid Buffer)
    //    hold: Load-Use 冒险时冻�?    //    flush: 跳转时冲�?(插入 NOP)
    // -----------------------------------------------------------------
    if_id if_id_inst (
        .clk          (clk),
        .rst          (rst),
        .push_valid_i (bp_if_valid),
        .consume_i    (if_id_consume_i),
        .inst_i       (inst_i),
        .inst_addr_i  (bp_fetch_pc_r),
        .pred_taken_i (bp_pred_taken_accepted_o),
        .raw_pred_taken_i(bp_pred_taken_o),
        .pred_target_i(bp_pred_target_o),
        .pred_ghr_i   (bp_pred_ghr_o),
        .inst_addr_o  (if_id_inst_addr_o),
        .pred_taken_o (if_id_pred_taken_o),
        .raw_pred_taken_o(if_id_raw_pred_taken_o),
        .pred_target_o(if_id_pred_target_o),
        .pred_ghr_o   (if_id_pred_ghr_o),
        .inst_o       (if_id_inst_o),
        .valid_o      (if_id_valid_o),
        .replaying_o  (if_id_replaying_o),
        .hold_flag_i  (front_hold_o),
        .flush_flag_i (ifid_flush_now)
    );

    // -----------------------------------------------------------------
    // 3. 通用寄存器堆
    //    读端�? 连接 ID 级的 rs1/rs2
    //    写端�? 连接 WB 级的写回信号
    // -----------------------------------------------------------------
    wire [31:0] issue_regs_rs1_rdata_o;
    wire [31:0] issue_regs_rs2_rdata_o;
    wire [31:0] issue_live_inst_o;
    wire [31:0] issue_live_inst_addr_o;
    wire [31:0] issue_live_op1_o;
    wire [31:0] issue_live_op2_o;
    wire [4:0]  issue_live_rd_addr_o;
    wire        issue_live_reg_wen_o;
    wire [31:0] issue_live_base_addr_o;
    wire [31:0] issue_live_addr_offset_o;
    wire        issue_live_mem_rd_reg_o;
    wire [14:0] issue_live_ctrl_flags_o;

    regs regs_inst (
        .clk          (clk),
        .reg1_raddr_i (id_rs1_addr_o),
        .reg2_raddr_i (id_rs2_addr_o),
        .reg1_rdata_o (regs_reg1_rdata_o),
        .reg2_rdata_o (regs_reg2_rdata_o),
        .reg3_raddr_i (id_pipe_inst_o[19:15]),
        .reg4_raddr_i (id_pipe_inst_o[24:20]),
        .reg3_rdata_o (issue_regs_rs1_rdata_o),
        .reg4_rdata_o (issue_regs_rs2_rdata_o),
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
        .mem_rd_reg_o  (data_read_en),
        .ctrl_flags_o  (id_ctrl_flags_o)
    );

    // Refresh operands at issue time so a stalled instruction can see
    // values that became available while it was waiting in front of EX.
    forwarding issue_forwarding_inst (
        .id_ex_inst_i        (id_inst_o),
        .id_ex_op1_i         (id_op1_o),
        .id_ex_op2_i         (id_op2_o),
        .id_ex_base_addr_i   (id_base_addr_o),
        .id_ex_addr_offset_i (id_addr_offset_o),
        .ex_mem_rd_addr_i    (ex_mem_pipe_rd_addr_o),
        .ex_mem_rd_data_i    (ex_mem_rd_data_o),
        .ex_mem_rd_wen_i     (ex_mem_rd_wen_o),
        .ex_mem_is_load_i    (ex_mem_is_load_o),
        .mem1_mem2_rd_addr_i (mem1_mem2_rd_addr_o),
        .mem1_mem2_rd_data_i (mem1_mem2_rd_data_o),
        .mem1_mem2_rd_wen_i  (mem1_mem2_rd_wen_o),
        .mem1_mem2_is_load_i (mem1_mem2_is_load_o),
        .mem2a_rd_addr_i     (mem2_align_rd_addr_o),
        .mem2a_rd_data_i     (mem2_align_rd_data_o),
        .mem2a_rd_wen_i      (mem2_align_rd_wen_o),
        .mem2a_is_load_i     (mem2_align_is_load_o),
        .mem2_rd_addr_i      (mem2_rd_addr_o),
        .mem2_rd_data_i      (mem2_rd_data_o),
        .mem2_rd_wen_i       (mem2_rd_wen_o),
        .mem_wb_rd_addr_i    (mem_wb_rd_addr_o),
        .mem_wb_rd_data_i    (mem_wb_rd_data_o),
        .mem_wb_rd_wen_i     (mem_wb_rd_wen_o),
        .wb_rd_addr_i        (wb_rd_addr_o),
        .wb_rd_data_i        (wb_rd_data_o),
        .wb_rd_wen_i         (wb_rd_wen_o),
        .fwd_op1_o           (issue_in_op1_o),
        .fwd_op2_o           (issue_in_op2_o),
        .fwd_base_addr_o     (issue_in_base_addr_o),
        .fwd_addr_offset_o   (issue_in_addr_offset_o)
    );

    issue_stage id_pipe_inst (
        .clk           (clk),
        .rst           (rst),
        .flush_i       (idpipe_flush_now),
        .issue_can_go_ex_i(issue_can_go_ex_o),
        .issue_ready_o (issue_ready_o),
        .issue_fire_o  (issue_fire_o),
        .issue_valid_o (issue_valid_o),
        .in_valid_i    (id_issue_valid_i),
        .inst_i        (id_inst_o),
        .inst_addr_i   (id_inst_addr_o),
        .op1_i         (issue_in_op1_o),
        .op2_i         (issue_in_op2_o),
        .pred_taken_i  (if_id_pred_taken_o),
        .raw_pred_taken_i(if_id_raw_pred_taken_o),
        .pred_target_i (if_id_pred_target_o),
        .pred_ghr_i    (if_id_pred_ghr_o),
        .rd_addr_i     (id_rd_addr_o),
        .reg_wen_i     (id_reg_wen),
        .base_addr_i   (issue_in_base_addr_o),
        .addr_offset_i (issue_in_addr_offset_o),
        .ctrl_flags_i  (id_ctrl_flags_o),
        .inst_o        (id_pipe_inst_o),
        .inst_addr_o   (id_pipe_inst_addr_o),
        .op1_o         (id_pipe_op1_o),
        .op2_o         (id_pipe_op2_o),
        .pred_taken_o  (id_pipe_pred_taken_o),
        .raw_pred_taken_o(id_pipe_raw_pred_taken_o),
        .pred_target_o (id_pipe_pred_target_o),
        .pred_ghr_o    (id_pipe_pred_ghr_o),
        .rd_addr_o     (id_pipe_rd_addr_o),
        .reg_wen_o     (id_pipe_reg_wen_o),
        .base_addr_o   (id_pipe_base_addr_o),
        .addr_offset_o (id_pipe_addr_offset_o),
        .ctrl_flags_o  (id_pipe_ctrl_flags_o)
    );

    id issue_refresh_id_inst (
        .inst_i        (id_pipe_inst_o),
        .inst_addr_i   (id_pipe_inst_addr_o),
        .rs1_data_i    (issue_regs_rs1_rdata_o),
        .rs2_data_i    (issue_regs_rs2_rdata_o),
        .rs1_addr_o    (),
        .rs2_addr_o    (),
        .inst_o        (issue_live_inst_o),
        .inst_addr_o   (issue_live_inst_addr_o),
        .op1_o         (issue_live_op1_o),
        .op2_o         (issue_live_op2_o),
        .rd_addr_o     (issue_live_rd_addr_o),
        .reg_wen       (issue_live_reg_wen_o),
        .base_addr_o   (issue_live_base_addr_o),
        .addr_offset_o (issue_live_addr_offset_o),
        .mem_rd_reg_o  (issue_live_mem_rd_reg_o),
        .ctrl_flags_o  (issue_live_ctrl_flags_o)
    );

    // Re-forward from the buffered issue slot at the moment it enters ID/EX.
    forwarding issue_emit_forwarding_inst (
        .id_ex_inst_i        (id_pipe_inst_o),
        .id_ex_op1_i         (issue_live_op1_o),
        .id_ex_op2_i         (issue_live_op2_o),
        .id_ex_base_addr_i   (issue_live_base_addr_o),
        .id_ex_addr_offset_i (issue_live_addr_offset_o),
        .ex_mem_rd_addr_i    (ex_mem_pipe_rd_addr_o),
        .ex_mem_rd_data_i    (ex_mem_rd_data_o),
        .ex_mem_rd_wen_i     (ex_mem_rd_wen_o),
        .ex_mem_is_load_i    (ex_mem_is_load_o),
        .mem1_mem2_rd_addr_i (mem1_mem2_rd_addr_o),
        .mem1_mem2_rd_data_i (mem1_mem2_rd_data_o),
        .mem1_mem2_rd_wen_i  (mem1_mem2_rd_wen_o),
        .mem1_mem2_is_load_i (mem1_mem2_is_load_o),
        .mem2a_rd_addr_i     (mem2_align_rd_addr_o),
        .mem2a_rd_data_i     (mem2_align_rd_data_o),
        .mem2a_rd_wen_i      (mem2_align_rd_wen_o),
        .mem2a_is_load_i     (mem2_align_is_load_o),
        .mem2_rd_addr_i      (mem2_rd_addr_o),
        .mem2_rd_data_i      (mem2_rd_data_o),
        .mem2_rd_wen_i       (mem2_rd_wen_o),
        .mem_wb_rd_addr_i    (mem_wb_rd_addr_o),
        .mem_wb_rd_data_i    (mem_wb_rd_data_o),
        .mem_wb_rd_wen_i     (mem_wb_rd_wen_o),
        .wb_rd_addr_i        (wb_rd_addr_o),
        .wb_rd_data_i        (wb_rd_data_o),
        .wb_rd_wen_i         (wb_rd_wen_o),
        .fwd_op1_o           (issue_emit_op1_o),
        .fwd_op2_o           (issue_emit_op2_o),
        .fwd_base_addr_o     (issue_emit_base_addr_o),
        .fwd_addr_offset_o   (issue_emit_addr_offset_o)
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
        .flush_flag_i  ((~issue_fire_o) | ctrl_flush_idex_o),
        .inst_i        (id_pipe_inst_o),
        .inst_addr_i   (id_pipe_inst_addr_o),
        .op1_i         (issue_emit_op1_o),
        .op2_i         (issue_emit_op2_o),
        .pred_taken_i  (id_pipe_pred_taken_o),
        .raw_pred_taken_i(id_pipe_raw_pred_taken_o),
        .pred_target_i (id_pipe_pred_target_o),
        .pred_ghr_i    (id_pipe_pred_ghr_o),
        .rd_addr_i     (id_pipe_rd_addr_o),
        .reg_wen_i     (id_pipe_reg_wen_o),
        .base_addr_i   (issue_emit_base_addr_o),
        .addr_offset_i (issue_emit_addr_offset_o),
        .ctrl_flags_i  (id_pipe_ctrl_flags_o),
        .inst_o        (id_ex_inst_o),
        .inst_addr_o   (id_ex_inst_addr_o),
        .op1_o         (id_ex_op1_o),
        .op2_o         (id_ex_op2_o),
        .pred_taken_o  (id_ex_pred_taken_o),
        .raw_pred_taken_o(id_ex_raw_pred_taken_o),
        .pred_target_o (id_ex_pred_target_o),
        .pred_ghr_o    (id_ex_pred_ghr_o),
        .rd_addr_o     (id_ex_rd_addr_o),
        .reg_wen_o     (id_ex_reg_wen),
        .base_addr_o   (id_ex_base_addr_o),
        .addr_offset_o (id_ex_addr_offset_o),
        .ctrl_flags_o  (id_ex_ctrl_flags_o)
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
        .mem1_mem2_is_load_i (mem1_mem2_is_load_o),
        .mem2a_rd_addr_i     (mem2_align_rd_addr_o),
        .mem2a_rd_data_i     (mem2_align_rd_data_o),
        .mem2a_rd_wen_i      (mem2_align_rd_wen_o),
        .mem2a_is_load_i     (mem2_align_is_load_o),
        .mem2_rd_addr_i      (mem2_rd_addr_o),
        .mem2_rd_data_i      (mem2_rd_data_o),
        .mem2_rd_wen_i       (mem2_rd_wen_o),
        .mem_wb_rd_addr_i    (mem_wb_rd_addr_o),
        .mem_wb_rd_data_i    (mem_wb_rd_data_o),
        .mem_wb_rd_wen_i     (mem_wb_rd_wen_o),
        .wb_rd_addr_i        (wb_rd_addr_o),
        .wb_rd_data_i        (wb_rd_data_o),
        .wb_rd_wen_i         (wb_rd_wen_o),
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
        .id_rs1_i     (hdu_id_rs1),
        .id_rs2_i     (hdu_id_rs2),
        .id_use_rs1_ex_i (hdu_id_use_rs1_ex),
        .id_use_rs2_ex_i (hdu_id_use_rs2_ex),
        .id_use_rs2_store_data_i (hdu_id_use_rs2_store_data),
        .ex_rd_i      (id_ex_rd_addr_o),
        .ex_is_load_i (id_ex_ctrl_flags_o[2]),
        .mem1_rd_i    (mem_out_rd_addr_o),
        .mem1_is_load_i (mem_out_is_load_o),
        .mem1_mem2_rd_i (mem1_mem2_rd_addr_o),
        .mem1_mem2_is_load_i (mem1_mem2_is_load_o),
        .mem2a_rd_i   (mem2_align_rd_addr_o),
        .mem2a_is_load_i (mem2_align_is_load_o),
        .hold_flag_o  (hdu_hold_req_o),
        .flush_flag_o (hdu_flush_req_o)
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
        .pred_taken_i  (id_ex_pred_taken_o),
        .pred_target_i (id_ex_pred_target_o),
        .pred_ghr_i    (id_ex_pred_ghr_o),
        .ctrl_flags_i  (id_ex_ctrl_flags_o),
        .rd_addr_i     (id_ex_rd_addr_o),
        .rd_wen_i      (id_ex_reg_wen),
        .kill_i        (ctrl_kill_ex_o),
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
        .inst_o        (ex_inst_o),
        .bp_update_en_o    (bp_update_en_o),
        .bp_update_pc_o    (bp_update_pc_o),
        .bp_update_ghr_o   (bp_update_ghr_o),
        .bp_ras_push_en_o  (bp_ras_push_en_o),
        .bp_ras_pop_en_o   (bp_ras_pop_en_o),
        .bp_ras_push_addr_o(bp_ras_push_addr_o),
        .bp_actual_taken_o (bp_actual_taken_o)
    );

    // -----------------------------------------------------------------
    // 7. 中央控制�?(CTRL)
    //    检测跳转，输出 2 拍冲刷信�?    // -----------------------------------------------------------------
    ctrl ctrl_inst (
        .clk          (clk),
        .rst          (rst),
        .jump_addr_i  (ex_jump_addr_o),
        .jump_en_i    (ex_jump_en_o),
        .redirect_hold_o (ctrl_redirect_hold_o),
        .jump_en_o    (ctrl_jump_en_o),
        .jump_addr_o  (ctrl_jump_addr_o),
        .kill_ex_o    (ctrl_kill_ex_o),
        .flush_ifid_o (ctrl_flush_ifid_o),
        .flush_idpipe_o (ctrl_flush_idpipe_o),
        .flush_idex_o (ctrl_flush_idex_o),
        .flush_flag_o ()
    );

    // -----------------------------------------------------------------
    // 8. EX/MEM1 流水线寄存器
    // -----------------------------------------------------------------
    ex_mem1 ex_mem_inst (
        .clk           (clk),
        .rst           (rst),
        .hold_flag_i   (1'b0),
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
        .mem1_mem2_rd_addr_i (mem1_mem2_rd_addr_o),
        .mem1_mem2_rd_data_i (mem1_mem2_rd_data_o),
        .mem1_mem2_rd_wen_i  (mem1_mem2_rd_wen_o),
        .mem1_mem2_is_load_i (mem1_mem2_is_load_o),
        .mem2a_rd_addr_i     (mem2_align_rd_addr_o),
        .mem2a_rd_data_i     (mem2_align_rd_data_o),
        .mem2a_rd_wen_i      (mem2_align_rd_wen_o),
        .mem2a_is_load_i     (mem2_align_is_load_o),
        .mem2_rd_addr_i      (mem2_rd_addr_o),
        .mem2_rd_data_i      (mem2_rd_data_o),
        .mem2_rd_wen_i       (mem2_rd_wen_o),
        .mem_wb_rd_addr_i    (mem_wb_rd_addr_o),
        .mem_wb_rd_data_i    (mem_wb_rd_data_o),
        .mem_wb_rd_wen_i     (mem_wb_rd_wen_o),
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
        .mem_rd_data_i (mem2_store_bypass_hit ? mem2_ram_data_i : ram_data_i),
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





