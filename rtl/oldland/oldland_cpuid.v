module oldland_cpuid(input wire [2:0]	reg_sel,
		     output reg [31:0]	val);

parameter cpuid_manufacturer = 0;
parameter cpuid_model = 0;

parameter cpu_clock_speed = 0;

parameter icache_size = 0;
parameter icache_line_size = 0;

parameter dcache_size = 0;
parameter dcache_line_size = 0;

localparam ICACHE_LINES = icache_size / icache_line_size;
localparam ICACHE_LINE_WORDS = icache_line_size / 4;

wire [31:0] cpuid0 = {cpuid_manufacturer[15:0], cpuid_model[15:0]};
wire [31:0] cpuid1 = cpu_clock_speed[31:0];
wire [31:0] cpuid2 = 32'b0;
wire [31:0] cpuid3 = {8'b0, ICACHE_LINES[15:0], ICACHE_LINE_WORDS[7:0]};
wire [31:0] cpuid4 = 32'b0;

always @(*) begin
	case (reg_sel)
	3'h0: val = cpuid0;
	3'h1: val = cpuid1;
	3'h2: val = cpuid2;
	3'h3: val = cpuid3;
	3'h4: val = cpuid4;
	default: val = 32'b0;
	endcase
end

endmodule
