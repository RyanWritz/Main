module TwoNToNPriorityEncoder(in, out); 

parameter int N = 8; 
parameter int log2N = 3;

input logic [N-1:0] in; 
output logic [log2N-1:0] out; 

always_comb
	begin 
		for(int i = 0; i< N; i++)
			begin 
				if(in[i] == 0) 
				begin
					out = out; 
				end
				else if(in[i] == 1) 
				begin
					out++;
				end
			end
	end


endmodule
