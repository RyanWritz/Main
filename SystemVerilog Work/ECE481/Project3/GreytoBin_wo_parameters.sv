module GreyToBin 
(output logic [3:0]out,
 input logic [3:0]in); 

int i;

always_comb
begin 
	for(i = 0; i < Bits; i++)
	begin
		if(i == Bits- 1)			//If MSB
		begin					//MSB of output
			out[i] = in[Bits-1]; 		//equal to MSB of input
		end 
		else 					//Else Output bit 
		begin 					//Equal to current bit XOR
			out[i] = in[i] ^ in[i+1];	//next highest bit 
		end
	end
end

endmodule 