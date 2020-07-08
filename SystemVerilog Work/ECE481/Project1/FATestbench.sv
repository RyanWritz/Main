module FATestbench;

logic Co, S;
logic A, B, Ci;

FA FullAdd(Co, S, A, B, Ci);

initial
begin
#5ns;
#5ns Ci = 0; B = 0; A = 0;	//{Ci,B,A} = 000		
#5ns A = 1;						//{Ci,B,A} = 001
#5ns B = 1; A = 0; 			//{Ci,B,A} = 010
#5ns A = 1;						//{Ci,B,A} = 011
#5ns Ci = 1; B = 0; A = 0;	//{Ci,B,A} = 100
#5ns A = 1;						//{Ci,B,A} = 101
#5ns B = 1; A = 0;			//{Ci,B,A} = 110
#5ns A = 1;						//{Ci,B,A} = 111
#5ns;
end
endmodule
