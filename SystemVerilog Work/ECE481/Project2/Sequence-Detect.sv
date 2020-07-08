//Ryan Writz and Priyam Shah (c) July 2019
//ECE 4/581 Project 2 Question 3
//Systm Verilog module of a sequencer detector. This detector compares the input sequence 
//with its own built-in sequence bit by bit. If the input sequence is identical to the 
//built-in sequence, it will display a message "matched", otherwise it will display 
//a message "not-matched". When the mismatched bit occurs, the detector will return to the
//initial state and process the next input bit as the beginning of a new sequence.
//Your built-in sequence is a 8-bit BCD code created by converting the last two 
//digits of the PSU ID number of one member of your group. Implement the detector
//by an FSM-based model in Systemverilog.

module SequenceDetect(output logic [11:0] Match, 		//Match output to contain a string 
input logic [7:0]Input,
input logic [3:0] Num1, Num2, 
input logic clk,reset);

logic [7:0] BuiltIn;	//Built in 8 digit BCD 
logic [7:0] TestVec;	//Test vector for checking bit by if 
logic [7:0] AllOnes = 8'b1111_1111;


[7:4]BuiltIn = [3:0] Num1;
[3:0]BuiltIn = [3:0] Num2;

int i;

always_ff @(posedge clk, posedge reset)
begin
	for(i = 0; i < 7; i++)
	begin 
		if(BuiltIn[i] == Input[i])	//Fills out a vector by comparing each 
			TestVec[i] <= 1;	//bit for a match between bulit in vs. given 
		else				//Vector then later used to check matching case 
			TestVec[i] <= 0;
	end
end

always_ff @(posedge clk, posedge reset)
begin
	for(i = 0; i < 7; i++)
	begin 
		if(TestVec & AllOnes == 1) 
			Match = "matched";
		else
			Match = "not-matched";
	end 
end 


endmodule