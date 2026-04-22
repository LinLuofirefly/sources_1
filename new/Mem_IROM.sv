module Mem_IROM (
    input  wire [11:0] addra,
    output reg  [31:0] douta,
    input  wire        clka,
    input  wire [31:0] dina
);
    reg [31:0] mem [0:4095];

    initial begin
        $readmemh("sim/irom.mem", mem);
    end

    always @(posedge clka) begin
        douta <= mem[addra];
    end
endmodule
