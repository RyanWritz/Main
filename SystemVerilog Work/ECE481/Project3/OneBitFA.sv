module OneBitFA
(output logic Co, S, 
input logic A, B, Ci);

logic X,Y,Z;

always_comb
begin
	X = A ^ B;
	S = Ci ^ X;
	Y = Ci & X;
	Z = A & B;
	Co = Y | Z; 
end

endmodule 