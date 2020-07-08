module d_ff(input logic d, clk, set, reset, output logic q); 

logic synch_reset; 

always_comb
	begin
		synch_reset = reset && clk; 
	end

always_ff @(negedge clk, set, posedge synch_reset)
	begin 
		if(set == 0)
			q <= 1; 
		else if (synch_reset == 1)
			q <= 0; 
		else 
			q <= d; 
	end

endmodule
