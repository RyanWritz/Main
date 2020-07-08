module FourBitFA
(output logic Co, [3:0]S, 
input logic [3:0]A, B, 
input logic Ci);

logic Co2,Co3,Co4;

OneBitFA FA1(Co, S[0], A[0], B[0], Ci);
OneBitFA FA2(Co2, S[1], A[1], B[1], Co);
OneBitFA FA3(Co3, S[2], A[2], B[2], Co2);
OneBitFA FA4(Co4, S[3], A[3], B[3], Co3);

endmodule 