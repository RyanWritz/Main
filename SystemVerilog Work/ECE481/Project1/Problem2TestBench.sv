module DecoderTestBench(); 

logic [7:0] outtest;
logic [2:0] intest;


initial 
	begin

		//Initialize First Three to Eight Decoder That Uses Boolean Operators

		//ThreetoEightdecoder(outtest, intest); 

		//Initialize Second Three to Eight Decoder That Uses Conditional Operators 

		//ThreeToEightDecoderConditional(outtest, intest); 

		//Initialize Third Three to Eight Decoder That Uses Shift Operators

		ThreeToEightShift(outtest, intest); 

		#100 outtest[2] = 0; outtest[1] = 0; outtest[0] = 0; 

		#100 outtest[2] = 0; outtest[1] = 0; outtest[0] = 1; 

		#100 outtest[2] = 0; outtest[1] = 1; outtest[0] = 0; 

		#100 outtest[2] = 0; outtest[1] = 1; outtest[0] = 1; 

		#100 outtest[2] = 1; outtest[1] = 0; outtest[0] = 0; 

		#100 outtest[2] = 1; outtest[1] = 0; outtest[0] = 1; 

		#100 outtest[2] = 1; outtest[1] = 1; outtest[0] = 0; 

		#100 outtest[2] = 1; outtest[1] = 1; outtest[0] = 1; 
	
	end

endmodule
