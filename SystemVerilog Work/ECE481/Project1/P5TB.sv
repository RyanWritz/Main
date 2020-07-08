module P5TB(); 

logic d, q, set, reset, clk; 


d_ff I1(d, clk, set, reset, q); 

initial 
	begin
		#100 d = 0; clk = 0; set = 0; reset = 0; 
	
		#100 d = 0; clk = 0; set = 0; reset = 1; 

		#100 d = 0; clk = 0; set = 1; reset = 0; 

		#100 d = 0; clk = 0; set = 1; reset = 1; 

		#100 d = 0; clk = 1; set = 0; reset = 0; 

		#100 d = 0; clk = 1; set = 0; reset = 1; 

		#100 d = 0; clk = 1; set = 1; reset = 0; 

		#100 d = 0; clk = 1; set = 1; reset = 1; 

		#100 d = 1; clk = 0; set = 0; reset = 0; 
	
		#100 d = 1; clk = 0; set = 0; reset = 1; 

		#100 d = 1; clk = 0; set = 1; reset = 0; 

		#100 d = 1; clk = 0; set = 1; reset = 1; 

		#100 d = 1; clk = 1; set = 0; reset = 0; 

		#100 d = 1; clk = 1; set = 0; reset = 1; 

		#100 d = 1; clk = 1; set = 1; reset = 0; 

		#100 d = 1; clk = 1; set = 1; reset = 1; 

	end 

endmodule
	