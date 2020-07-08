//Ryan Writz and Priyam Shah (c) July 2019
//ECE 4/581 Project 1 Question 7
//SystemVerilog model of a state machine that detects a sequence 
//of three logic 1’s occurring at the input and that asserts a logic 1
//at the output during the last state of the sequence. 
//E.g. the sequence 001011101111 would produce an output 000000100011.
/*	Model after this where {A,B,C} first 3 digits of input
	if({A,B,C} === 3'b111)		//If 3 1's in a row set last digit in three 
		{Ap,Bp,Cp} = 3'b001;	//to 1
	else
		{Ap,Bp,Cp} = 3'b000;
*/


module TriBitCheck
#(parameter Bits = 12)			//Number of bits in bus 
(output logic [Bits - 1: 0] Out, input logic [Bits - 1: 0] In);

int i;

always_comb
begin 
	for(i = 0; i < 8; i++)			//Increment till 1st to 10th bit are checked as leading bit in sequence
		if({In[i],In[i+1],In[i+2]} === 3'b111)		//If 3 1's in a row set last digit in three 
			{Out[i],Out[i+1],Out[i+2]} = 3'b001;	//to 1
		else
			{Out[i],Out[i+1],Out[i+2]} = 3'b000;	//else set to 0s

end

endmodule 
