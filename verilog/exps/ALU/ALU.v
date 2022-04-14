
module ALU (
	input [2:0] sel,
	input [3:0] A,
	input [3:0] B, 
	output reg [3:0] result, 
	output reg zero, 
	output reg carry,
	output reg overflow);

	wire [3:0]result0;
	reg sub;
	assign sub = (sel=='b001);
	addsub4 addsub4inst1(.A(A), .B(B), .sub(sub), .result(result0), .carry(carry), .overflow(overflow), .zero(zero));
	always @(*)
	begin 
	    case(sel[2:0])
            'b000: result = result0;
            'b001: result = result0;
            'b010: result = ~A;
            'b011: result = A & B;
            'b100: result = A | B;
            'b101: result = A ^ B;
            /* verilator lint_off WIDTH */
            'b110: result = (A < B);
            /* verilator lint_off WIDTH */
            'b111: result = (A == B);
            default: result = 'b0000;
	    endcase
	end
	
endmodule

