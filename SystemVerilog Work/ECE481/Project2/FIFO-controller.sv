//Ryan Writz and Priyam Shah (c) July 2019
//ECE 4/581 Project 2 Question 1
//SystemVerilog model of a FIFO controller where a FIFO, 
//is a type of memory that stores data serially, where the
//first word read is the first word that was stored. 
//The module controls the reading and writing of data from/into a FIFO.
//The FIFO is a two-port RAM array having separate read and write data 
//buses, separate read and write address buses, a write signal and 
//a read signal. The size of the RAM array is 32 x 8 bits. 
//Data is read from and written into the FIFO at the same rate 
//(a very trivial case of the FIFO).


module FIFOControl #(parameter N = 4)
(output logic [N-1:0] rd_ptr, wr_ptr, 
output logic wr_en, rd_en, emp, full,   
input logic clk, wr, rd,f_reset);

logic [N:0] count_rd = 0;
logic [N:0] count_wr = 0;
logic rd_reset,wr_reset;

bincount #(N) BCRD(count_rd,rd_reset,clk);	//binary counter of rd_ptr to maintain empty/full conditions
bincount #(N) BCWR(count_wr,wr_reset,clk);	//binarhy counter of wr_ptr to maintain empty/full conditions

//Intializing the FIFO pointers
always_ff
begin	
	rd_reset <= f_reset;		//makes f_reset serve as master reset so that all resets on same page 
	wr_reset <= f_reset;
end

always_ff @ (posedge clk, posedge f_reset)
begin 
	if(f_reset)			//At reset, both pointers are initialized to point to the first location of the FIFO 
	begin				//emp is made high and full is made low.
		rd_ptr <= 0;		 
		wr_ptr <= 0;
		emp <= 1;
		full <= 0;
	end
	if(rd & ~emp)			//If an external device wishes to read data from the FIFO by 
	begin
		rd_en <= 1;		//asserting rd, then the controller asserts rd_en only if emp is deasserted.
	end
	if(wr & full)			//A similar logic exists for the write operation. The crux of this design
		wr_en <= 1;		//is in determining the conditions which lead to the assertion/deassertion
					//of the emp and full signals.
	if(rd_en)			//The read pointer rd_ptr contains the address of the next FIFO location to be read
	begin 
		//rd operation here
		rd_ptr <= rd_ptr + 1;	
	end
	if(wr_en)			//write pointer wr_ptr contains the address of the next FIFO location to be written
	begin 
		//wr operation here 
		wr_ptr <= wr_ptr + 1;
	end 
	if(~f_reset & count_rd[N] != count_wr[N]) 
		full <= 1;
	if(~f_reset & count_rd[N] == count_wr[N])
		emp <= 1;
	if(full)
		wr_en <= 0;
	else if(emp)
		rd_en <= 0;

end
endmodule 