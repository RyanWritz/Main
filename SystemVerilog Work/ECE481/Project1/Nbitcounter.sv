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
//Count <= 0;		

always_ff @(posedge clk, negedge reset) 
begin	
	if(~reset)								
		Count <= 0;							//If reset asserted set count to 0 
	if(Up & Count < (2**Bits -1))			//If less than highest count and Up
		Count <= Count + 1;					//Increase count 
	if (Up & Count == (2**Bits -1))			//If equal to highest count and Up
		Count <= Count;						//Do not increase count to avoid wrapping 
	else if (~Up)							//Up == 0
		Count <= Count - 1;					//Decrease count
end
endmodule
