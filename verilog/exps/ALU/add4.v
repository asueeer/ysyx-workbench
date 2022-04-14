module add4(
	input [3:0] A,
	input [3:0] B,
	input cin,
	output [3:0] result,
	output carry,
	output reg overflow
);
    /* verilator lint_off WIDTH */
    assign {carry, result} = A + B + cin;

    // 若参加加法运算的变量符号相同,
    // 而运算结果的符号与之不同,
    // 说明溢出.
    assign overflow = (A[3] == B[3]) & (result[3] != A[3]);
endmodule
