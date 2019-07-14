//Ryan Writz and Priyam Shah (c) July 2019
//ECE 4/581 Project 1 Question 1 
//SystemVerilog description of a full adder as a netlist of AND and OR gates
//and inverters w/o gate delays
//Side note: Standard Full Adder would be
/*module FA(output logic Co, S, input logic A, B, Ci);
logic X,Y,Z;

xor E1(X,A,B);		// X = A ^ B
xor E2(S,Ci,X);		// S = Ci ^ X
and A1(Y,Ci,X);		// Y = Ci & X
and A2(Z,A,B);		// Z = A & B
or O1(Co,Y,Z);		// Co = Y | Z 

endmodule  */
//However as we are limited to AND, OR and inverters must make do 
module FA(output logic Co, S, input logic A, B, Ci);
logic Q,R,T,U,V,W,X,Y,Z;

//Effectively becomes X = A ^ B
and A1(Q,A,B);		// Q = A & B
not I1(R,Q);		// R = ~Q
or O1(T,A,B);		// T = A | B
and A2(X,R,T);		// X = R & T

//Effectively becomes S = Ci ^ X
and A3(U,X,Ci);		// U = X & Ci
not I2(W,U);		// W = ~U
or O2(V,X,Ci);		// V = X | Ci
and A4(S,W,V);		// S = W & V

and A5(Y,Ci,X);		// Y = Ci & X
and A6(Z,A,B);		// Z = A & B
or O3(Co,Y,Z);		// Co = Y | Z 

endmodule 