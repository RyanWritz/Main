module ProjectThreeTestBench(); 

logic [7:0] intest; 
logic [2:0] outtest; 

TwoNToNPriorityEncode T1(intest, outtest); 

initial 

	begin

		#100 intest[7] = 0; intest[6] = 0; intest[5] = 0; intest[4] = 0; intest[3] = 0; intest[2] = 0; intest[1] = 0; intest[0] = 1; 

		#100 intest[7] = 0; intest[6] = 0; intest[5] = 0; intest[4] = 0; intest[3] = 0; intest[2] = 0; intest[1] = 1; intest[0] = 1; 

		#100 intest[7] = 0; intest[6] = 0; intest[5] = 0; intest[4] = 0; intest[3] = 0; intest[2] = 1; intest[1] = 1; intest[0] = 1; 

		#100 intest[7] = 0; intest[6] = 0; intest[5] = 0; intest[4] = 0; intest[3] = 1; intest[2] = 1; intest[1] = 1; intest[0] = 1; 

		#100 intest[7] = 0; intest[6] = 0; intest[5] = 0; intest[4] = 1; intest[3] = 1; intest[2] = 1; intest[1] = 1; intest[0] = 1; 

		#100 intest[7] = 0; intest[6] = 0; intest[5] = 1; intest[4] = 1; intest[3] = 1; intest[2] = 1; intest[1] = 1; intest[0] = 1; 

		#100 intest[7] = 0; intest[6] =1; intest[5] = 1; intest[4] = 1; intest[3] = 1; intest[2] =1; intest[1] = 1; intest[0] = 1; 

		#100 intest[7] = 1; intest[6] = 1; intest[5] = 1; intest[4] =1; intest[3] = 1; intest[2] = 1; intest[1] = 1; intest[0] = 1; 
	
	end


endmodule
