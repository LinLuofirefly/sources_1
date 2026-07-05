`timescale 1ns / 1ps
`include "defines.v"

module id_ex (
    input  wire        clk,
    input  wire        rst,
    input  wire        hold_flag_i,
    input  wire        flush_flag_i,

    input  wire [31:0] inst_i,
    input  wire [31:0] inst_addr_i,
    input  wire [31:0] op1_i,
    input  wire [31:0] op2_i,
    input  wire [31:0] cmp_op2_i,
    input  wire [31:0] store_data_i,
    input  wire        pred_taken_i,
    input  wire [31:0] pred_target_i,
    input  wire [`BP_GHR_WIDTH-1:0] pred_ghr_i,
    input  wire [4:0]  rs1_addr_i,
    input  wire [4:0]  rs2_addr_i,
    input  wire        use_rs1_i,
    input  wire        use_rs2_i,
    input  wire        use_base_addr_i,
    input  wire [4:0]  rd_addr_i,
    input  wire        reg_wen_i,
    input  wire [31:0] base_addr_i,
    input  wire [31:0] branch_offset_i,
    input  wire [31:0] mem_offset_i,
    input  wire [31:0] jump_offset_i,
    input  wire [2:0]  ex_func3_i,
    input  wire        ex_func7_bit5_i,
    input  wire        ex_func7_is_r_i,
    input  wire        ex_func7_is_sub_i,
    input  wire        ex_is_op_imm_i,
    input  wire        ex_is_op_reg_i,
    input  wire        ex_is_branch_i,
    input  wire        ex_is_load_i,
    input  wire        ex_is_store_i,
    input  wire        ex_is_jal_i,
    input  wire        ex_is_jalr_i,
    input  wire        ex_is_auipc_i,
    input  wire        ex_is_lui_i,
    input  wire        ex_is_system_i,
    input  wire        ex_is_rv32m_i,
    input  wire        ex_is_csr_op_i,
    input  wire        ex_is_call_jal_i,
    input  wire        ex_ras_should_push_jalr_i,
    input  wire        ex_ras_should_pop_jalr_i,
    input  wire        ex_ras_predicted_jalr_i,

    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg [31:0] inst_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg [31:0] inst_addr_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg [31:0] op1_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg [31:0] op2_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg [31:0] cmp_op2_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg [31:0] store_data_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        pred_taken_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg [31:0] pred_target_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg [`BP_GHR_WIDTH-1:0] pred_ghr_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg [4:0]  rs1_addr_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg [4:0]  rs2_addr_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        use_rs1_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        use_rs2_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        use_base_addr_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg [4:0]  rd_addr_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        reg_wen_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg [31:0] base_addr_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg [31:0] branch_offset_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg [31:0] mem_offset_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg [31:0] jump_offset_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg [2:0]  ex_func3_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        ex_func7_bit5_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        ex_func7_is_r_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        ex_func7_is_sub_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        ex_is_op_imm_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        ex_is_op_reg_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        ex_is_branch_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        ex_is_load_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        ex_is_store_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        ex_is_jal_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        ex_is_jalr_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        ex_is_auipc_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        ex_is_lui_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        ex_is_system_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        ex_is_rv32m_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        ex_is_csr_op_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        ex_is_call_jal_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        ex_ras_should_push_jalr_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        ex_ras_should_pop_jalr_o,
    (* extract_enable = "no" *) (* max_fanout = 8 *)output reg        ex_ras_predicted_jalr_o
);

    (* max_fanout = 8 *)wire [31:0] inst_next =
        flush_flag_i ? `INST_NOP :
        hold_flag_i  ? inst_o    :
                       inst_i;

   (* max_fanout = 8 *) wire [31:0] inst_addr_next =
        flush_flag_i ? 32'b0       :
        hold_flag_i  ? inst_addr_o :
                       inst_addr_i;

    (* max_fanout = 8 *) wire [31:0] op1_next =
        flush_flag_i ? 32'b0 :
        hold_flag_i  ? op1_o :
                       op1_i;

    (* max_fanout = 8 *) wire [31:0] op2_next =
        flush_flag_i ? 32'b0 :
        hold_flag_i  ? op2_o :
                       op2_i;

    (* max_fanout = 8 *) wire [31:0] cmp_op2_next =
        flush_flag_i ? 32'b0 :
        hold_flag_i  ? cmp_op2_o :
                       cmp_op2_i;

    (* max_fanout = 8 *) wire [31:0] store_data_next =
        flush_flag_i ? 32'b0 :
        hold_flag_i  ? store_data_o :
                       store_data_i;

    (* max_fanout = 8 *) wire pred_taken_next =
        flush_flag_i ? 1'b0         :
        hold_flag_i  ? pred_taken_o :
                       pred_taken_i;

    (* max_fanout = 8 *) wire [31:0] pred_target_next =
        flush_flag_i ? 32'b0         :
        hold_flag_i  ? pred_target_o :
                       pred_target_i;

    (* max_fanout = 8 *)wire [`BP_GHR_WIDTH-1:0] pred_ghr_next =
        flush_flag_i ? {`BP_GHR_WIDTH{1'b0}} :
        hold_flag_i  ? pred_ghr_o :
                       pred_ghr_i;

    (* max_fanout = 8 *)wire [4:0] rs1_addr_next =
        flush_flag_i ? 5'b0       :
        hold_flag_i  ? rs1_addr_o :
                       rs1_addr_i;

    (* max_fanout = 8 *)wire [4:0] rs2_addr_next =
        flush_flag_i ? 5'b0       :
        hold_flag_i  ? rs2_addr_o :
                       rs2_addr_i;

    (* max_fanout = 8 *)wire use_rs1_next =
        flush_flag_i ? 1'b0      :
        hold_flag_i  ? use_rs1_o :
                       use_rs1_i;

    (* max_fanout = 8 *)wire use_rs2_next =
        flush_flag_i ? 1'b0      :
        hold_flag_i  ? use_rs2_o :
                       use_rs2_i;

    (* max_fanout = 8 *)wire use_base_addr_next =
        flush_flag_i ? 1'b0            :
        hold_flag_i  ? use_base_addr_o :
                       use_base_addr_i;

    (* max_fanout = 8 *)wire [4:0] rd_addr_next =
        flush_flag_i ? 5'b0      :
        hold_flag_i  ? rd_addr_o :
                       rd_addr_i;

    (* max_fanout = 8 *)wire reg_wen_next =
        flush_flag_i ? 1'b0      :
        hold_flag_i  ? reg_wen_o :
                       reg_wen_i;

    (* max_fanout = 8 *)wire [31:0] base_addr_next =
        flush_flag_i ? 32'b0       :
        hold_flag_i  ? base_addr_o :
                       base_addr_i;

    (* max_fanout = 8 *)wire [31:0] branch_offset_next =
        flush_flag_i ? 32'b0         :
        hold_flag_i  ? branch_offset_o :
                       branch_offset_i;

    (* max_fanout = 8 *)wire [31:0] mem_offset_next =
        flush_flag_i ? 32'b0      :
        hold_flag_i  ? mem_offset_o :
                       mem_offset_i;

    (* max_fanout = 8 *)wire [31:0] jump_offset_next =
        flush_flag_i ? 32'b0       :
        hold_flag_i  ? jump_offset_o :
                       jump_offset_i;

    (* max_fanout = 8 *)wire [2:0] ex_func3_next =
        flush_flag_i ? 3'b0 :
        hold_flag_i  ? ex_func3_o :
                       ex_func3_i;

    (* max_fanout = 8 *)wire ex_func7_bit5_next =
        flush_flag_i ? 1'b0 :
        hold_flag_i  ? ex_func7_bit5_o :
                       ex_func7_bit5_i;

    (* max_fanout = 8 *)wire ex_func7_is_r_next =
        flush_flag_i ? 1'b0 :
        hold_flag_i  ? ex_func7_is_r_o :
                       ex_func7_is_r_i;

    (* max_fanout = 8 *)wire ex_func7_is_sub_next =
        flush_flag_i ? 1'b0 :
        hold_flag_i  ? ex_func7_is_sub_o :
                       ex_func7_is_sub_i;

    (* max_fanout = 8 *)wire ex_is_op_imm_next =
        flush_flag_i ? 1'b0 :
        hold_flag_i  ? ex_is_op_imm_o :
                       ex_is_op_imm_i;

    (* max_fanout = 8 *)wire ex_is_op_reg_next =
        flush_flag_i ? 1'b0 :
        hold_flag_i  ? ex_is_op_reg_o :
                       ex_is_op_reg_i;

    (* max_fanout = 8 *)wire ex_is_branch_next =
        flush_flag_i ? 1'b0 :
        hold_flag_i  ? ex_is_branch_o :
                       ex_is_branch_i;

    (* max_fanout = 8 *)wire ex_is_load_next =
        flush_flag_i ? 1'b0 :
        hold_flag_i  ? ex_is_load_o :
                       ex_is_load_i;

    (* max_fanout = 8 *)wire ex_is_store_next =
        flush_flag_i ? 1'b0 :
        hold_flag_i  ? ex_is_store_o :
                       ex_is_store_i;

    (* max_fanout = 8 *)wire ex_is_jal_next =
        flush_flag_i ? 1'b0 :
        hold_flag_i  ? ex_is_jal_o :
                       ex_is_jal_i;

    (* max_fanout = 8 *)wire ex_is_jalr_next =
        flush_flag_i ? 1'b0 :
        hold_flag_i  ? ex_is_jalr_o :
                       ex_is_jalr_i;

    (* max_fanout = 8 *)wire ex_is_auipc_next =
        flush_flag_i ? 1'b0 :
        hold_flag_i  ? ex_is_auipc_o :
                       ex_is_auipc_i;

    (* max_fanout = 8 *)wire ex_is_lui_next =
        flush_flag_i ? 1'b0 :
        hold_flag_i  ? ex_is_lui_o :
                       ex_is_lui_i;

    (* max_fanout = 8 *)wire ex_is_system_next =
        flush_flag_i ? 1'b0 :
        hold_flag_i  ? ex_is_system_o :
                       ex_is_system_i;

    (* max_fanout = 8 *)wire ex_is_rv32m_next =
        flush_flag_i ? 1'b0 :
        hold_flag_i  ? ex_is_rv32m_o :
                       ex_is_rv32m_i;

    (* max_fanout = 8 *)wire ex_is_csr_op_next =
        flush_flag_i ? 1'b0 :
        hold_flag_i  ? ex_is_csr_op_o :
                       ex_is_csr_op_i;

    (* max_fanout = 8 *)wire ex_is_call_jal_next =
        flush_flag_i ? 1'b0 :
        hold_flag_i  ? ex_is_call_jal_o :
                       ex_is_call_jal_i;

    (* max_fanout = 8 *)wire ex_ras_should_push_jalr_next =
        flush_flag_i ? 1'b0 :
        hold_flag_i  ? ex_ras_should_push_jalr_o :
                       ex_ras_should_push_jalr_i;

    (* max_fanout = 8 *)wire ex_ras_should_pop_jalr_next =
        flush_flag_i ? 1'b0 :
        hold_flag_i  ? ex_ras_should_pop_jalr_o :
                       ex_ras_should_pop_jalr_i;

    (* max_fanout = 8 *)wire ex_ras_predicted_jalr_next =
        flush_flag_i ? 1'b0 :
        hold_flag_i  ? ex_ras_predicted_jalr_o :
                       ex_ras_predicted_jalr_i;

    always @(posedge clk) begin
        if (rst == 1'b0) begin
            inst_o          <= `INST_NOP;
            inst_addr_o     <= 32'b0;
            op1_o           <= 32'b0;
            op2_o           <= 32'b0;
            cmp_op2_o       <= 32'b0;
            store_data_o    <= 32'b0;
            pred_taken_o    <= 1'b0;
            pred_target_o   <= 32'b0;
            pred_ghr_o      <= {`BP_GHR_WIDTH{1'b0}};
            rs1_addr_o      <= 5'b0;
            rs2_addr_o      <= 5'b0;
            use_rs1_o       <= 1'b0;
            use_rs2_o       <= 1'b0;
            use_base_addr_o <= 1'b0;
            rd_addr_o       <= 5'b0;
            reg_wen_o       <= 1'b0;
            base_addr_o     <= 32'b0;
            branch_offset_o <= 32'b0;
            mem_offset_o    <= 32'b0;
            jump_offset_o   <= 32'b0;
            ex_func3_o      <= 3'b0;
            ex_func7_bit5_o <= 1'b0;
            ex_func7_is_r_o <= 1'b0;
            ex_func7_is_sub_o <= 1'b0;
            ex_is_op_imm_o  <= 1'b0;
            ex_is_op_reg_o  <= 1'b0;
            ex_is_branch_o  <= 1'b0;
            ex_is_load_o    <= 1'b0;
            ex_is_store_o   <= 1'b0;
            ex_is_jal_o     <= 1'b0;
            ex_is_jalr_o    <= 1'b0;
            ex_is_auipc_o   <= 1'b0;
            ex_is_lui_o     <= 1'b0;
            ex_is_system_o  <= 1'b0;
            ex_is_rv32m_o   <= 1'b0;
            ex_is_csr_op_o  <= 1'b0;
            ex_is_call_jal_o <= 1'b0;
            ex_ras_should_push_jalr_o <= 1'b0;
            ex_ras_should_pop_jalr_o  <= 1'b0;
            ex_ras_predicted_jalr_o   <= 1'b0;
        end else begin
            inst_o          <= inst_next;
            inst_addr_o     <= inst_addr_next;
            op1_o           <= op1_next;
            op2_o           <= op2_next;
            cmp_op2_o       <= cmp_op2_next;
            store_data_o    <= store_data_next;
            pred_taken_o    <= pred_taken_next;
            pred_target_o   <= pred_target_next;
            pred_ghr_o      <= pred_ghr_next;
            rs1_addr_o      <= rs1_addr_next;
            rs2_addr_o      <= rs2_addr_next;
            use_rs1_o       <= use_rs1_next;
            use_rs2_o       <= use_rs2_next;
            use_base_addr_o <= use_base_addr_next;
            rd_addr_o       <= rd_addr_next;
            reg_wen_o       <= reg_wen_next;
            base_addr_o     <= base_addr_next;
            branch_offset_o <= branch_offset_next;
            mem_offset_o    <= mem_offset_next;
            jump_offset_o   <= jump_offset_next;
            ex_func3_o      <= ex_func3_next;
            ex_func7_bit5_o <= ex_func7_bit5_next;
            ex_func7_is_r_o <= ex_func7_is_r_next;
            ex_func7_is_sub_o <= ex_func7_is_sub_next;
            ex_is_op_imm_o  <= ex_is_op_imm_next;
            ex_is_op_reg_o  <= ex_is_op_reg_next;
            ex_is_branch_o  <= ex_is_branch_next;
            ex_is_load_o    <= ex_is_load_next;
            ex_is_store_o   <= ex_is_store_next;
            ex_is_jal_o     <= ex_is_jal_next;
            ex_is_jalr_o    <= ex_is_jalr_next;
            ex_is_auipc_o   <= ex_is_auipc_next;
            ex_is_lui_o     <= ex_is_lui_next;
            ex_is_system_o  <= ex_is_system_next;
            ex_is_rv32m_o   <= ex_is_rv32m_next;
            ex_is_csr_op_o  <= ex_is_csr_op_next;
            ex_is_call_jal_o <= ex_is_call_jal_next;
            ex_ras_should_push_jalr_o <= ex_ras_should_push_jalr_next;
            ex_ras_should_pop_jalr_o  <= ex_ras_should_pop_jalr_next;
            ex_ras_predicted_jalr_o   <= ex_ras_predicted_jalr_next;
        end
    end

endmodule
