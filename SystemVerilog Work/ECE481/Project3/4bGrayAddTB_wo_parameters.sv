module GrayCodAddTB();

logic [5:0]BinAddResult;
logic [4:0] GreyCode1,GreyCode2;


NBitGrayCodeAdd GCAdd(BinAddResult,GreyCode1,GreyCode2);

int i;

initial 
begin 

	#5 GreyCode1 = 0; GreyCode2 = 0;
	for(i = 0; i <16; i++)
	begin	
		#5 GreyCode2 = 1;
		#5 GreyCode2 = 3;
		#5 GreyCode2 = 2;
		#5 GreyCode2 = 6;
		#5 GreyCode2 = 4;
		#5 GreyCode2 = 5;
		#5 GreyCode2 = 7;
		#5 GreyCode2 = 15;
		#5 GreyCode2 = 14;
		#5 GreyCode2 = 12;
		#5 GreyCode2 = 13;
		#5 GreyCode2 = 9;
		#5 GreyCode2 = 11;
		#5 GreyCode2 = 10;
		#5 GreyCode2 = 8;
		#5 GreyCode1 = GreyCode1 + 1;
	end
	
end 
/*logic BinCode1,BinCode;

GreyToBin #(N-1) GTBC1(BinCode1,GreyCode1);	//1st 4-bit grey-to-binary converter
GreyToBin #(N-1) GTBC2(BinCode2,GreyCode2);	//2nd 4-bit grey-to-binary converter
FourBitFA AddBinFour(Co, Sum, BinCode1,BinCode2);	//Four Bit Binary Adder
BinaryToGreyCode #(N) BTGC1(BinAddResult,Co,Sum);	//5-bit binary-to-grey code converter 
*/


endmodule 
