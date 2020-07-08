//Ryan Writz and Priyam Shah (c) July 2019
//ECE 4/581 Project 2 Question 1
//Designed a 4-bit grey code adder by creating two 4-bit grey-to-binary converters,
// a 4-bit binary adder, and a 5-bit binary-to-grey code convertor, modeling the 
// design as a combinational block, ie. two 4 bit grey code inputs
//d) Write one test bench to verify the SV model.
//e) Synthesize the design and show the complexity (gate counts), area, and power of synthesized circuits using report command from DC. (Choose osu05_stdcells.db as your target library, generate the netlist file in Verilog)
//f) Go back to your simulator, and simulate the synthesized Verilog netlist by including std05_stdcell.v as the standard cell library.
//g) By simulation, verify the SV model and the synthesized Verilog netlist with the same testbench.


module NBitGrayCodeAdd #(parameter N = 5) 
(output logic [N:0] BinAddResult,
input logic [N-1:0] GreyCode1,GreyCode2);


logic [N-1:0] BinCode1,BinCode2,Sum;
logic Ci = 0;
logic Co;

GreyToBin #(N-1) GTBC1(BinCode1,GreyCode1);	//1st 4-bit grey-to-binary converter
GreyToBin #(N-1) GTBC2(BinCode2,GreyCode2);	//2nd 4-bit grey-to-binary converter
FourBitFA AddBinFour(Co, Sum, BinCode1,BinCode2,Ci);	//Four Bit Binary Adder
GreyToBin #(N) BTGC1(BinAddResult,{Co,Sum});	//5-bit binary-to-grey code converter 

endmodule 
