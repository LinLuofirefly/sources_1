`include "defines.v"

module csr (
    input  wire        clk,
    input  wire        rst,
    input  wire        valid_i,
    input  wire [31:0] inst_i,
    input  wire [31:0] inst_addr_i,
    input  wire [31:0] csr_src_i,
    output reg  [31:0] csr_rdata_o,
    output reg  [31:0] trap_jump_addr_o,
    output wire        trap_jump_en_o
);

    wire [2:0]  func3    = inst_i[14:12];
    wire [11:0] csr_addr = inst_i[31:20];
    wire [6:0]  opcode   = inst_i[6:0];

    wire is_system = (opcode == `INST_SYSTEM);
    wire is_csr_op = is_system &&
                     ((func3 == `INST_CSRRW)  || (func3 == `INST_CSRRS)  || (func3 == `INST_CSRRC) ||
                      (func3 == `INST_CSRRWI) || (func3 == `INST_CSRRSI) || (func3 == `INST_CSRRCI));
    wire is_ecall  = (inst_i == `INST_ECALL);
    wire is_mret   = (inst_i == `INST_MRET);

    reg [31:0] mstatus_r;
    reg [31:0] mtvec_r;
    reg [31:0] mscratch_r;
    reg [31:0] mepc_r;
    reg [31:0] mcause_r;
    reg [31:0] csr_wdata_r;

    wire csr_write_en = is_csr_op &&
                        ((func3 == `INST_CSRRW)  || (func3 == `INST_CSRRWI) ||
                        (((func3 == `INST_CSRRS)  || (func3 == `INST_CSRRC) ||
                          (func3 == `INST_CSRRSI) || (func3 == `INST_CSRRCI)) && (csr_src_i != 32'b0)));

    assign trap_jump_en_o = valid_i && (is_ecall || is_mret);

    always @(*) begin
        case (csr_addr)
            `CSR_MSTATUS: csr_rdata_o = mstatus_r;
            `CSR_MTVEC:   csr_rdata_o = mtvec_r;
            `CSR_MSCRATCH: csr_rdata_o = mscratch_r;
            `CSR_MEPC:    csr_rdata_o = mepc_r;
            `CSR_MCAUSE:  csr_rdata_o = mcause_r;
            default:      csr_rdata_o = 32'b0;
        endcase

        case (func3)
            `INST_CSRRW, `INST_CSRRWI: csr_wdata_r = csr_src_i;
            `INST_CSRRS, `INST_CSRRSI: csr_wdata_r = csr_rdata_o | csr_src_i;
            `INST_CSRRC, `INST_CSRRCI: csr_wdata_r = csr_rdata_o & (~csr_src_i);
            default:                   csr_wdata_r = csr_rdata_o;
        endcase

        trap_jump_addr_o = is_mret ? mepc_r : {mtvec_r[31:2], 2'b00};
    end

    always @(posedge clk) begin
        if (rst == 1'b0) begin
            mstatus_r <= 32'b0;
            mtvec_r   <= 32'b0;
            mscratch_r<= 32'b0;
            mepc_r    <= 32'b0;
            mcause_r  <= 32'b0;
        end else if (valid_i == 1'b1) begin
            if (is_ecall) begin
                mepc_r       <= inst_addr_i;
                mcause_r     <= 32'd11;
                mstatus_r[7] <= mstatus_r[3];
                mstatus_r[3] <= 1'b0;
            end else if (is_mret) begin
                mstatus_r[3] <= mstatus_r[7];
                mstatus_r[7] <= 1'b1;
            end else if (csr_write_en) begin
                case (csr_addr)
                    `CSR_MSTATUS: mstatus_r <= csr_wdata_r;
                    `CSR_MTVEC:   mtvec_r   <= csr_wdata_r;
                    `CSR_MSCRATCH: mscratch_r <= csr_wdata_r;
                    `CSR_MEPC:    mepc_r    <= csr_wdata_r;
                    `CSR_MCAUSE:  mcause_r  <= csr_wdata_r;
                    default: begin end
                endcase
            end
        end
    end

endmodule
