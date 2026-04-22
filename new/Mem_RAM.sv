module Mem_RAM (
    input  wire        clka,
    input  wire [15:0] addra,
    input  wire [31:0] dina,
    output reg  [31:0] douta,
    input  wire        ena,
    input  wire [3:0]  wea,
    input  wire        clkb,
    input  wire [15:0] addrb,
    input  wire [31:0] dinb,
    output reg  [31:0] doutb,
    input  wire        enb,
    input  wire [3:0]  web
);
    reg [31:0] mem [0:65535];
    integer i;

    initial begin
        for (i = 0; i < 65536; i = i + 1) begin
            mem[i] = 32'h0000_0000;
        end
        $readmemh("sim/dram.mem", mem);
    end

    always @(posedge clka) begin
        if (ena) begin
            if (wea[0]) mem[addra][7:0]   <= dina[7:0];
            if (wea[1]) mem[addra][15:8]  <= dina[15:8];
            if (wea[2]) mem[addra][23:16] <= dina[23:16];
            if (wea[3]) mem[addra][31:24] <= dina[31:24];
        end
        douta <= mem[addra];
    end

    always @(posedge clkb) begin
        if (enb) begin
            doutb <= mem[addrb];
        end
        if (|web) begin
            if (web[0]) mem[addrb][7:0]   <= dinb[7:0];
            if (web[1]) mem[addrb][15:8]  <= dinb[15:8];
            if (web[2]) mem[addrb][23:16] <= dinb[23:16];
            if (web[3]) mem[addrb][31:24] <= dinb[31:24];
        end
    end
endmodule
