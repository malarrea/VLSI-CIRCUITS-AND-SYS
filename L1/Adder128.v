module Adder128 (A, B, cin, sum, cout);
input [127:0] A, B;
input cin;
output [127:0] sum;
output cout;
assign {cout, sum} = A + B + cin;
endmodule
