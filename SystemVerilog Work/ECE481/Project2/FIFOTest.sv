module FIFOTest();

parameter N = 4;			//Number of initial bits for pointers 

logic clk, n_reset;
logic [N:0]count;



FIFOControl #(N) FIFO(rd_ptr, wr_ptr, wr_en,
rd_en, emp, full, clk, wr, rd,f_reset);


initial 
begin 
	clk = 0;
	forever #5 clk = ~clk;
end

initial
	#5 f_reset = 1;			//Start two pointers at same location with reset 
	#5 f_reset = 0; rd = 1;		//Tries to read but will fail since empty 
	#5 wr = 1;			//writes for 5 cycles
	#25 wr = 0; rd = 1;		//read for 5 cycles 
end


endmodule 
