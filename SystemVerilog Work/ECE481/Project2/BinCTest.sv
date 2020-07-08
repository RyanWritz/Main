module BinCTest();

parameter N = 3;

logic clk, n_reset;
logic [N - 1:0]count;

bincount #(N) BC(count, n_reset, clk);

initial 
begin 
	clk = 0;
	forever #5 clk = ~clk;
end

initial 
begin
	#5 n_reset = 1;
	#10 n_reset = 0;
	#300 n_reset = 1;

end

endmodule 
