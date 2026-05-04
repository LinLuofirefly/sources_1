`include "defines.v"

module mem1 (
    input  wire [31:0] inst_i,
    input  wire [4:0]  rd_addr_i,
    input  wire [31:0] rd_data_i,
    input  wire        rd_wen_i,
    input  wire [31:0] mem_rd_addr_i,
    input  wire [3:0]  mem_wd_reg_i,
    input  wire [31:0] mem_wd_addr_i,
    input  wire [31:0] mem_wd_data_i,
    input  wire        is_load_i,

    input  wire [4:0]  mem1_mem2_rd_addr_i,
    input  wire [31:0] mem1_mem2_rd_data_i,
    input  wire        mem1_mem2_rd_wen_i,
    input  wire        mem1_mem2_is_load_i,

    input  wire [4:0]  mem2a_rd_addr_i,
    input  wire [31:0] mem2a_rd_data_i,
    input  wire        mem2a_rd_wen_i,
    input  wire        mem2a_is_load_i,

    input  wire [4:0]  mem2_rd_addr_i,
    input  wire [31:0] mem2_rd_data_i,
    input  wire        mem2_rd_wen_i,

    input  wire [4:0]  mem_wb_rd_addr_i,
    input  wire [31:0] mem_wb_rd_data_i,
    input  wire        mem_wb_rd_wen_i,

    output wire [4:0]  rd_addr_o,
    output wire [31:0] rd_data_o,
    output wire        rd_wen_o,
    output wire [31:0] mem_rd_addr_o,
    output wire [3:0]  mem_wd_reg_o,
    output wire [31:0] mem_wd_addr_o,
    output wire [31:0] mem_wd_data_o,
    output wire [31:0] inst_o,
    output wire        is_load_o
);

    wire [6:0] opcode   = inst_i[6:0];
    wire [4:0] rs2      = inst_i[24:20];
    wire       is_store = (opcode == `INST_TYPE_S);

    wire store_fwd_from_mem1_mem2 = is_store && (rs2 != 5'b0) &&
                                    mem1_mem2_rd_wen_i &&
                                    (mem1_mem2_rd_addr_i == rs2) &&
                                    !mem1_mem2_is_load_i;
    wire store_fwd_from_mem2a     = is_store && (rs2 != 5'b0) &&
                                    mem2a_rd_wen_i &&
                                    (mem2a_rd_addr_i == rs2) &&
                                    !mem2a_is_load_i;
    wire store_fwd_from_mem2      = is_store && (rs2 != 5'b0) &&
                                    mem2_rd_wen_i &&
                                    (mem2_rd_addr_i == rs2);
    wire store_fwd_from_mem_wb    = is_store && (rs2 != 5'b0) &&
                                    mem_wb_rd_wen_i &&
                                    (mem_wb_rd_addr_i == rs2);

    reg [31:0] store_data_final_r;
    reg [31:0] store_data_raw_r;
    reg        store_data_forwarded_r;

    always @(*) begin
        store_data_final_r     = mem_wd_data_i;
        store_data_raw_r       = 32'b0;
        store_data_forwarded_r = 1'b0;

        if (is_store && (rs2 != 5'b0)) begin
            if (store_fwd_from_mem1_mem2) begin
                store_data_raw_r       = mem1_mem2_rd_data_i;
                store_data_forwarded_r = 1'b1;
            end else if (store_fwd_from_mem2a) begin
                store_data_raw_r       = mem2a_rd_data_i;
                store_data_forwarded_r = 1'b1;
            end else if (store_fwd_from_mem2) begin
                store_data_raw_r       = mem2_rd_data_i;
                store_data_forwarded_r = 1'b1;
            end else if (store_fwd_from_mem_wb) begin
                store_data_raw_r       = mem_wb_rd_data_i;
                store_data_forwarded_r = 1'b1;
            end

        end
    end

    assign rd_addr_o     = rd_addr_i;
    assign rd_data_o     = rd_data_i;
    assign rd_wen_o      = rd_wen_i;
    assign mem_rd_addr_o = mem_rd_addr_i;
    assign mem_wd_reg_o  = mem_wd_reg_i;
    assign mem_wd_addr_o = mem_wd_addr_i;
    assign mem_wd_data_o = store_data_final_r;
    assign inst_o        = inst_i;
    assign is_load_o     = is_load_i;

endmodule
