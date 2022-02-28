// 四选一2位选择器
module mux41v2(
    input [1:0] x0,
    input [1:0] x1,
    input [1:0] x2,
    input [1:0] x3,
    input [1:0] y,
    output [1:0]f
);
    always @(*)
    begin
        case(y)
            0: f = x0;
            1: f = x1;
            2: f = x2;
            3: f = x3;
            default: ;
        endcase
    end
endmodule