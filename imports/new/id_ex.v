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
    input  wire [8:0]  pred_ghr_i,
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

    (* extract_enable = "no" *) output reg [31:0] inst_o,
    (* extract_enable = "no" *) output reg [31:0] inst_addr_o,
    (* extract_enable = "no" *) output reg [31:0] op1_o,
    (* extract_enable = "no" *) output reg [31:0] op2_o,
    (* extract_enable = "no" *) output reg [31:0] cmp_op2_o,
    (* extract_enable = "no" *) output reg [31:0] store_data_o,
    (* extract_enable = "no" *) output reg        pred_taken_o,
    (* extract_enable = "no" *) output reg [31:0] pred_target_o,
    (* extract_enable = "no" *) output reg [8:0]  pred_ghr_o,
    (* extract_enable = "no" *) output reg [4:0]  rs1_addr_o,
    (* extract_enable = "no" *) output reg [4:0]  rs2_addr_o,
    (* extract_enable = "no" *) output reg        use_rs1_o,
    (* extract_enable = "no" *) output reg        use_rs2_o,
    (* extract_enable = "no" *) output reg        use_base_addr_o,
    (* extract_enable = "no" *) output reg [4:0]  rd_addr_o,
    (* extract_enable = "no" *) output reg        reg_wen_o,
    (* extract_enable = "no" *) output reg [31:0] base_addr_o,
    (* extract_enable = "no" *) output reg [31:0] branch_offset_o,
    (* extract_enable = "no" *) output reg [31:0] mem_offset_o,
    (* extract_enable = "no" *) output reg [31:0] jump_offset_o
);

    wire [31:0] inst_next =
        flush_flag_i ? `INST_NOP :
        hold_flag_i  ? inst_o    :
                       inst_i;

    wire [31:0] inst_addr_next =
        flush_flag_i ? 32'b0       :
        hold_flag_i  ? inst_addr_o :
                       inst_addr_i;

    wire [31:0] op1_next =
        flush_flag_i ? 32'b0 :
        hold_flag_i  ? op1_o :
                       op1_i;

    wire [31:0] op2_next =
        flush_flag_i ? 32'b0 :
        hold_flag_i  ? op2_o :
                       op2_i;

    wire [31:0] cmp_op2_next =
        flush_flag_i ? 32'b0 :
        hold_flag_i  ? cmp_op2_o :
                       cmp_op2_i;

    wire [31:0] store_data_next =
        flush_flag_i ? 32'b0 :
        hold_flag_i  ? store_data_o :
                       store_data_i;

    wire pred_taken_next =
        flush_flag_i ? 1'b0         :
        hold_flag_i  ? pred_taken_o :
                       pred_taken_i;

    wire [31:0] pred_target_next =
        flush_flag_i ? 32'b0         :
        hold_flag_i  ? pred_target_o :
                       pred_target_i;

    wire [8:0] pred_ghr_next =
        flush_flag_i ? 9'b0       :
        hold_flag_i  ? pred_ghr_o :
                       pred_ghr_i;

    wire [4:0] rs1_addr_next =
        flush_flag_i ? 5'b0       :
        hold_flag_i  ? rs1_addr_o :
                       rs1_addr_i;

    wire [4:0] rs2_addr_next =
        flush_flag_i ? 5'b0       :
        hold_flag_i  ? rs2_addr_o :
                       rs2_addr_i;

    wire use_rs1_next =
        flush_flag_i ? 1'b0      :
        hold_flag_i  ? use_rs1_o :
                       use_rs1_i;

    wire use_rs2_next =
        flush_flag_i ? 1'b0      :
        hold_flag_i  ? use_rs2_o :
                       use_rs2_i;

    wire use_base_addr_next =
        flush_flag_i ? 1'b0            :
        hold_flag_i  ? use_base_addr_o :
                       use_base_addr_i;

    wire [4:0] rd_addr_next =
        flush_flag_i ? 5'b0      :
        hold_flag_i  ? rd_addr_o :
                       rd_addr_i;

    wire reg_wen_next =
        flush_flag_i ? 1'b0      :
        hold_flag_i  ? reg_wen_o :
                       reg_wen_i;

    wire [31:0] base_addr_next =
        flush_flag_i ? 32'b0       :
        hold_flag_i  ? base_addr_o :
                       base_addr_i;

    wire [31:0] branch_offset_next =
        flush_flag_i ? 32'b0         :
        hold_flag_i  ? branch_offset_o :
                       branch_offset_i;

    wire [31:0] mem_offset_next =
        flush_flag_i ? 32'b0      :
        hold_flag_i  ? mem_offset_o :
                       mem_offset_i;

    wire [31:0] jump_offset_next =
        flush_flag_i ? 32'b0       :
        hold_flag_i  ? jump_offset_o :
                       jump_offset_i;

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
            pred_ghr_o      <= 9'b0;
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
        end
    end

endmodule
