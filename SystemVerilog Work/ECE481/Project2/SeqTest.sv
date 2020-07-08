module SeqTest();

logic [11:0] Match;
logic [7:0] Num1;
logic [7:0] Num2;

SequenceDetect SeqDet(Match,Input,Num1, Num2,clk,reset);

initial 
begin 
	clk = 0;
	forever #5 clk = ~clk;
end

initial
begin
	#5 $display("%s",Match);
end



endmodule 
