//Ryan Writz and Priyam Shah (c) July 2019
//ECE 4/581 Project 1 Question 6
//SystemVerilog model of an N-bit counter with a 
//control input “Up”. When the control input is ‘1’ the 
//counter counts up; when it is ‘0’ the counter counts down.
//The counter should not wrap round. When the all ‘1’s or
//all ‘0’s states are reached the counter should stop

module Nbitcount
#(parameter Bits = 4)
(output logic [Bits-1:0]Count, input logic Up,clk,reset);

//intializes count to 0 regardless of number of bits 
Count <= 0;		

always_ff @(posedge clk, negedge
begin
	case(Count)
	begin
		0: 				Count <= Count;		//Up == X, count remains at zero 
		(2**Bits -1):	Count <= 
		default: 		Count <= Count + 1;	//Up == 1, increase count 
	end 

	
	/*	if(Up == 1 & Count < (2**Bits -1))
		Count <= Count + 1;
	else if (Up == 1 & Count < (2**Bits -1)	
		Count <= 0;
	else 								//Up == 0
		Count <= Count - 1;	*/			//Decrease count
end
endmodule
