`include "defines.v"

module forwarding (
    input  wire [31:0] id_ex_op1_i,
    input  wire [31:0] id_ex_op2_i,
    input  wire [31:0] id_ex_cmp_op2_i,
    input  wire [31:0] id_ex_store_data_i,
    input  wire [31:0] id_ex_base_addr_i,

    input  wire [4:0]  id_ex_rs1_addr_i,
    input  wire [4:0]  id_ex_rs2_addr_i,

    input  wire        id_ex_is_branch_i,
    input  wire        id_ex_is_jalr_i,

    input  wire        id_ex_use_rs1_i,
    input  wire        id_ex_use_rs2_i,
    input  wire        id_ex_use_base_addr_i,

    input  wire [4:0]  ex_mem_rd_addr_i,
    input  wire [31:0] ex_mem_rd_data_i,
    input  wire        ex_mem_rd_wen_i,
    input  wire        ex_mem_is_load_i,

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
    input  wire        mem2_is_slow_load_i,

    input  wire [4:0]  mem_wb_rd_addr_i,
    input  wire [31:0] mem_wb_rd_data_i,
    input  wire        mem_wb_rd_wen_i,
    input  wire        mem_wb_is_slow_load_i,

    output reg  [31:0] fwd_op1_o,
    output reg  [31:0] fwd_op2_o,
    output reg  [31:0] fwd_cmp_op2_o,
    output reg  [31:0] fwd_store_data_o,
    output reg  [31:0] fwd_base_addr_o
);

    localparam [2:0] SEL_ID_EX     = 3'd0;
    localparam [2:0] SEL_EX_MEM    = 3'd1;
    localparam [2:0] SEL_MEM1_MEM2 = 3'd2;
    localparam [2:0] SEL_MEM2A     = 3'd3;
    localparam [2:0] SEL_MEM2      = 3'd4;
    localparam [2:0] SEL_MEM_WB    = 3'd5;

    // ================================================================
    // ALU op1 forwarding
    //
    // branch 的 rs1 会进入 branch compare -> PC。
    // 因此 branch 时禁止 op1 forwarding。
    // 非 branch 的普通 ALU 仍然保留完整 forwarding。
    // ================================================================

    wire rs1_match_ex_mem =
        id_ex_use_rs1_i &&
        !id_ex_is_branch_i &&
        (id_ex_rs1_addr_i != 5'b0) &&
        ex_mem_rd_wen_i &&
        (ex_mem_rd_addr_i == id_ex_rs1_addr_i) &&
        !ex_mem_is_load_i;

    wire rs1_match_mem1_mem2 =
        id_ex_use_rs1_i &&
        !id_ex_is_branch_i &&
        (id_ex_rs1_addr_i != 5'b0) &&
        mem1_mem2_rd_wen_i &&
        (mem1_mem2_rd_addr_i == id_ex_rs1_addr_i) &&
        !mem1_mem2_is_load_i;

    wire rs1_match_mem2a =
        id_ex_use_rs1_i &&
        !id_ex_is_branch_i &&
        (id_ex_rs1_addr_i != 5'b0) &&
        mem2a_rd_wen_i &&
        (mem2a_rd_addr_i == id_ex_rs1_addr_i) &&
        !mem2a_is_load_i;

    wire rs1_match_mem2 =
        id_ex_use_rs1_i &&
        !id_ex_is_branch_i &&
        (id_ex_rs1_addr_i != 5'b0) &&
        mem2_rd_wen_i &&
        (mem2_rd_addr_i == id_ex_rs1_addr_i) &&
        !mem2_is_slow_load_i;

    wire rs1_match_mem_wb =
        id_ex_use_rs1_i &&
        !id_ex_is_branch_i &&
        (id_ex_rs1_addr_i != 5'b0) &&
        mem_wb_rd_wen_i &&
        (mem_wb_rd_addr_i == id_ex_rs1_addr_i) &&
        !mem_wb_is_slow_load_i;

    wire [2:0] rs1_sel =
        rs1_match_ex_mem    ? SEL_EX_MEM :
        rs1_match_mem1_mem2 ? SEL_MEM1_MEM2 :
        rs1_match_mem2a     ? SEL_MEM2A :
        rs1_match_mem2      ? SEL_MEM2 :
        rs1_match_mem_wb    ? SEL_MEM_WB :
                              SEL_ID_EX;

    // ================================================================
    // ALU op2 forwarding
    //
    // 普通 ALU op2 不影响 PC，保留完整 forwarding。
    // ================================================================

    wire rs2_alu_match_ex_mem =
        id_ex_use_rs2_i &&
        (id_ex_rs2_addr_i != 5'b0) &&
        ex_mem_rd_wen_i &&
        (ex_mem_rd_addr_i == id_ex_rs2_addr_i) &&
        !ex_mem_is_load_i;

    wire rs2_alu_match_mem1_mem2 =
        id_ex_use_rs2_i &&
        (id_ex_rs2_addr_i != 5'b0) &&
        mem1_mem2_rd_wen_i &&
        (mem1_mem2_rd_addr_i == id_ex_rs2_addr_i) &&
        !mem1_mem2_is_load_i;

    wire rs2_alu_match_mem2a =
        id_ex_use_rs2_i &&
        (id_ex_rs2_addr_i != 5'b0) &&
        mem2a_rd_wen_i &&
        (mem2a_rd_addr_i == id_ex_rs2_addr_i) &&
        !mem2a_is_load_i;

    wire rs2_alu_match_mem2 =
        id_ex_use_rs2_i &&
        (id_ex_rs2_addr_i != 5'b0) &&
        mem2_rd_wen_i &&
        (mem2_rd_addr_i == id_ex_rs2_addr_i) &&
        !mem2_is_slow_load_i;

    wire rs2_alu_match_mem_wb =
        id_ex_use_rs2_i &&
        (id_ex_rs2_addr_i != 5'b0) &&
        mem_wb_rd_wen_i &&
        (mem_wb_rd_addr_i == id_ex_rs2_addr_i) &&
        !mem_wb_is_slow_load_i;

    wire [2:0] rs2_alu_sel =
        rs2_alu_match_ex_mem    ? SEL_EX_MEM :
        rs2_alu_match_mem1_mem2 ? SEL_MEM1_MEM2 :
        rs2_alu_match_mem2a     ? SEL_MEM2A :
        rs2_alu_match_mem2      ? SEL_MEM2 :
        rs2_alu_match_mem_wb    ? SEL_MEM_WB :
                                  SEL_ID_EX;

    // ================================================================
    // Branch compare rs2 forwarding
    //
    // 完全禁止 branch compare operand2 forwarding。
    // branch 的 rs2 只使用 ID/EX 中已经读好的 cmp_op2。
    // ================================================================

    wire [2:0] rs2_cmp_sel =
        id_ex_is_branch_i ? SEL_ID_EX : rs2_alu_sel;

    // ================================================================
    // Store data forwarding
    //
    // store data 不影响 PC，保留完整 forwarding。
    // ================================================================

    wire [2:0] rs2_store_sel = rs2_alu_sel;

    // ================================================================
    // Base address forwarding
    //
    // load/store base 需要 forwarding，否则栈和访存地址会错。
    // JALR/RET base 会影响 PC，因此只在 JALR 时禁止 base forwarding。
    // ================================================================

    wire base_match_ex_mem =
        id_ex_use_base_addr_i &&
        !id_ex_is_jalr_i &&
        (id_ex_rs1_addr_i != 5'b0) &&
        ex_mem_rd_wen_i &&
        (ex_mem_rd_addr_i == id_ex_rs1_addr_i) &&
        !ex_mem_is_load_i;

    wire base_match_mem1_mem2 =
        id_ex_use_base_addr_i &&
        !id_ex_is_jalr_i &&
        (id_ex_rs1_addr_i != 5'b0) &&
        mem1_mem2_rd_wen_i &&
        (mem1_mem2_rd_addr_i == id_ex_rs1_addr_i) &&
        !mem1_mem2_is_load_i;

    wire base_match_mem2a =
        id_ex_use_base_addr_i &&
        !id_ex_is_jalr_i &&
        (id_ex_rs1_addr_i != 5'b0) &&
        mem2a_rd_wen_i &&
        (mem2a_rd_addr_i == id_ex_rs1_addr_i) &&
        !mem2a_is_load_i;

    wire base_match_mem2 =
        id_ex_use_base_addr_i &&
        !id_ex_is_jalr_i &&
        (id_ex_rs1_addr_i != 5'b0) &&
        mem2_rd_wen_i &&
        (mem2_rd_addr_i == id_ex_rs1_addr_i) &&
        !mem2_is_slow_load_i;

    wire base_match_mem_wb =
        id_ex_use_base_addr_i &&
        !id_ex_is_jalr_i &&
        (id_ex_rs1_addr_i != 5'b0) &&
        mem_wb_rd_wen_i &&
        (mem_wb_rd_addr_i == id_ex_rs1_addr_i) &&
        !mem_wb_is_slow_load_i;

    wire [2:0] base_sel =
        base_match_ex_mem    ? SEL_EX_MEM :
        base_match_mem1_mem2 ? SEL_MEM1_MEM2 :
        base_match_mem2a     ? SEL_MEM2A :
        base_match_mem2      ? SEL_MEM2 :
        base_match_mem_wb    ? SEL_MEM_WB :
                               SEL_ID_EX;

    always @(*) begin
        case (rs1_sel)
            SEL_EX_MEM:    fwd_op1_o = ex_mem_rd_data_i;
            SEL_MEM1_MEM2: fwd_op1_o = mem1_mem2_rd_data_i;
            SEL_MEM2A:     fwd_op1_o = mem2a_rd_data_i;
            SEL_MEM2:      fwd_op1_o = mem2_rd_data_i;
            SEL_MEM_WB:    fwd_op1_o = mem_wb_rd_data_i;
            default:       fwd_op1_o = id_ex_op1_i;
        endcase

        case (rs2_alu_sel)
            SEL_EX_MEM:    fwd_op2_o = ex_mem_rd_data_i;
            SEL_MEM1_MEM2: fwd_op2_o = mem1_mem2_rd_data_i;
            SEL_MEM2A:     fwd_op2_o = mem2a_rd_data_i;
            SEL_MEM2:      fwd_op2_o = mem2_rd_data_i;
            SEL_MEM_WB:    fwd_op2_o = mem_wb_rd_data_i;
            default:       fwd_op2_o = id_ex_op2_i;
        endcase

        case (rs2_cmp_sel)
            SEL_EX_MEM:    fwd_cmp_op2_o = ex_mem_rd_data_i;
            SEL_MEM1_MEM2: fwd_cmp_op2_o = mem1_mem2_rd_data_i;
            SEL_MEM2A:     fwd_cmp_op2_o = mem2a_rd_data_i;
            SEL_MEM2:      fwd_cmp_op2_o = mem2_rd_data_i;
            SEL_MEM_WB:    fwd_cmp_op2_o = mem_wb_rd_data_i;
            default:       fwd_cmp_op2_o = id_ex_cmp_op2_i;
        endcase

        case (rs2_store_sel)
            SEL_EX_MEM:    fwd_store_data_o = ex_mem_rd_data_i;
            SEL_MEM1_MEM2: fwd_store_data_o = mem1_mem2_rd_data_i;
            SEL_MEM2A:     fwd_store_data_o = mem2a_rd_data_i;
            SEL_MEM2:      fwd_store_data_o = mem2_rd_data_i;
            SEL_MEM_WB:    fwd_store_data_o = mem_wb_rd_data_i;
            default:       fwd_store_data_o = id_ex_store_data_i;
        endcase

        case (base_sel)
            SEL_EX_MEM:    fwd_base_addr_o = ex_mem_rd_data_i;
            SEL_MEM1_MEM2: fwd_base_addr_o = mem1_mem2_rd_data_i;
            SEL_MEM2A:     fwd_base_addr_o = mem2a_rd_data_i;
            SEL_MEM2:      fwd_base_addr_o = mem2_rd_data_i;
            SEL_MEM_WB:    fwd_base_addr_o = mem_wb_rd_data_i;
            default:       fwd_base_addr_o = id_ex_base_addr_i;
        endcase
    end

endmodule
