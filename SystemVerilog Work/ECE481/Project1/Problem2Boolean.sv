module ThreetoEightdecoder(output logic [7:0] out, input logic [2:0] in); 

	/*

	Accidentally did gate instantiations

	logic [2:0] inverter; 
	
	not n0(inverter[0], in[0]);
	not n1(inverter[1], in[1]); 
	not n2(inverter[2], in[2]); 
	
	and a0(out[0], inverter[2], inverter[1], inverter[0]); 
	and a1(out[1], inverter[2], inverter[1], in[0]); 
	and a2(out[2], inverter[2], in[1], inverter[0]); 
	and a3(out[3], inverter[2], in[1], in[0]); 
	and a4(out[4], in[2], inverter[1], inverter[0]); 
	and a5(out[5], in[2], inverter[1], in[0]); 
	and a6(out[6], in[2], in[1], inverter[0]); 
	and a7(out[7], in[2], in[2], in[0]); 


	*/ 

	always_comb

		begin 

			out[0] = ~in[2] && ~in[1] && ~in[0]; 
			
			out[1] = ~in[2] && ~in[1] && in[0]; 
			
			out[2] = ~in[2] && in[1] && ~in[0]; 
			
			out[3] = ~in[2] && in[1] && in[0]; 

			out[4] = in[2] && ~in[1] && ~in[0]; 
			
			out[5] = in[2] && ~in[1] && in[0]; 

			out[6] = in[2] && in[1] && ~in[0]; 

			out[7] = in[2] && in[1] && in[0]; 

		end

endmodule 

	
