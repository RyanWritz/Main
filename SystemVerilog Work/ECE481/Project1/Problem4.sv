module BinaryToGreyCode(in, out); 

parameter int Bits = 3; 

input logic  [Bits-1:0] in; 
output logic [Bits-1:0] out; 
int i = 0;

always_comb
	begin 
		for(i = 0; i < Bits; i++)
		begin
			if(i == Bits- 1)
				begin
					out[i] = in[Bits-1]; 
				end 
			else 
				begin 
					out[i] = in[i] ^ in[i+1];
				end
		end
	end

endmodule 	
		
		
