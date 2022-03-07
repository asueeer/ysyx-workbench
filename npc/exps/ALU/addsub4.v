module addsub4(
	input [3:0] A,
	input [3:0] B,
	input sub,
	output reg [3:0] result,
	output reg zero,
	output reg carry,
	output reg overflow
);
	wire [3:0] B1;
	assign B1 = B ^ {4{sub}};
    add4 add4inst1(.A(A), .B(B1), .cin(sub), .result(result), .carry(carry), .overflow(overflow));
    assign zero = (result == 'b0000);
endmodule

