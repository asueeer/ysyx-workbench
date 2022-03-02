module ALU (
	input [2:0] sel,
	input [3:0] A,
	input [3:0] B, 
	output reg [3:0] result, 
	output reg zero, 
	output reg carry,
	output reg overflow);
	
	always @(*)
	begin 
		// case(sel[2:0])
	end
	
endmodule

module addsub4(
	input [3:0] A,
	input [3:0] B,
	input sub,
	output reg [3:0] result,
	output reg zero,
	output reg carry,
	output reg overflow
);
    
	wire B1;
	assign B1 = B ^ {32{sub}};
    add4 add4inst1(.A(A), .B(B1), .cin(sub), .result(result), .carry(carry), .overflow(overflow));

endmodule


module add4(
	input [3:0] A,
	input [3:0] B,
	input cin,
	output [3:0] result,
	output carry,
	output reg overflow
);
    assign {carry, result} = A + B + cin;

    // 若参加加法运算的变量符号相同,
    // 而运算结果的符号与之不同,
    // 说明溢出.
    assign overflow = (A[3] == B[3]) && (result[3] != A[3]);
endmodule
