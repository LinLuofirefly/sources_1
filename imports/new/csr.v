`timescale 1ns / 1ps
`include "defines.v"

// ============================================================================
// 简化机器态 CSR 单元
// ----------------------------------------------------------------------------
// 支持 mstatus/mtvec/mscratch/mepc/mcause 的基本读写，以及 ecall/mret 跳转。
// CSR 指令在 EX 阶段执行：
//   - CSRRS/CSRRC 当 rs1=x0 时不写 CSR；
//   - CSRRSI/CSRRCI 当 uimm=0 时不写 CSR；
//   - ecall 保存 mepc/mcause 并跳到 mtvec；
//   - mret 跳回 mepc。
// ============================================================================
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
    wire [4:0]  rs1_addr = inst_i[19:15];
    wire [4:0]  csr_uimm = inst_i[19:15];

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

    // RISC-V 规定 CSRRS/CSRRC 的源为 0 时只读不写，立即数形式同理。
    wire csr_write_en = is_csr_op &&
                        ((func3 == `INST_CSRRW)  || (func3 == `INST_CSRRWI) ||
                        (((func3 == `INST_CSRRS)  || (func3 == `INST_CSRRC))  && (rs1_addr != 5'b0)) ||
                        (((func3 == `INST_CSRRSI) || (func3 == `INST_CSRRCI)) && (csr_uimm != 5'b0)));

    assign trap_jump_en_o = valid_i && (is_ecall || is_mret);

    // 组合读 CSR，并同时计算写回 CSR 的新值和 trap 目标地址。
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

    // CSR 状态寄存器同步更新；valid_i 被 kill 时为 0，避免旧路径指令改 CSR。
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
