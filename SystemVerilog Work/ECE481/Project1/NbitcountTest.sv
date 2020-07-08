module NBitTest;

logic [3:0] Count;
logic Up, clk, reset;

Nbitcount #(4) TestNbit(Count, Up, clk, reset);


initial 
begin 
	clk=0;
	forever #5 clk=~clk;
end

initial 
begin
	reset = 1;				//Intial reset to clear count 
#5	reset = 0; Up = 1;
#25 Up = 0;					//Multiple clock pulse to test increase and switch to decrease
end
endmodule 