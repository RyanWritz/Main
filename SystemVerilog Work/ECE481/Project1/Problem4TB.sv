module Problem4TB(); 

logic [2:0] intest; 
logic [2:0] outtest; 

BinaryToGreyCode F1(intest, outtest); 

initial 

	begin

		#100 intest[2] = 0; intest[1] = 0; intest[0] = 0; 

		#100 intest[2] = 0; intest[1] = 0; intest[0] = 1; 

		#100 intest[2] = 0; intest[1] = 1; intest[0] = 0; 

		#100 intest[2] = 0; intest[1] = 1; intest[0] = 1; 

		#100 intest[2] = 1; intest[1] = 0; intest[0] = 0; 

		#100 intest[2] = 1; intest[1] = 0; intest[0] = 1; 

		#100 intest[2] = 1; intest[1] = 1; intest[0] = 0; 

		#100 intest[2] = 1; intest[1] = 1; intest[0] = 1; 

	
	end

endmodule

