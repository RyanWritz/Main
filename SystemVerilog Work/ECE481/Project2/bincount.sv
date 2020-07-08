//Simple N bit binary counter with 
//active high asynchronous reset 

module bincount #(parameter N = 3)
(output logic [N-1:0]count, 
input logic n_reset, clk);

always_ff @ (posedge clk, negedge n_reset)
begin
	if(n_reset)
		count <= 0;
	else 
		count <= count + 1;
end 


endmodule 
