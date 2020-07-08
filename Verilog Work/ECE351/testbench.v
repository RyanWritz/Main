//Ryan W. Writz (c) June 8th,2017
//ECE 351 Hw 8- Barrel Shifter 
//This testbench exhaustively tests the barrel shifter to make sure that any data 
//bit combination coming in, any combination of bits for the opcode and any 
//combination of the number of bits to shift are all accounted for. 

module testbench;

wire [4:0]q;  
reg [4:0]data;
reg [1:0]bitnum;
reg [3:0]opcode; 
reg reset,clock;
integer i = 0;
integer k = 0;
 
barrelshift U1(.Q(q), .D(data), .S(bitnum), .Op(opcode), .Reset(reset), .clk(clock)); 

initial 
  begin  
  data=5'b00000; opcode=4'b0000;
  for(k=0;k<32;k=k+1)
  begin
  bitnum=2'b01;
  #5; clock=1;
  #5; clock=0;
  for(i=0;i<16;i=i+1)
    begin 
      	#5; clock=1;
     	#5; opcode = opcode + 4'b0001;
      	#5; clock=0;
    end
  #5; bitnum=2'b10;
  for(i=0;i<16;i=i+1)
    begin
      	#5; clock=1;
      	#5; opcode = opcode + 4'b0001;
      	#5; clock=0;
    end  
  #5; bitnum=2'b11;
  for(i=0;i<16;i=i+1)
    begin
      	#5; clock=1;
      	#5; opcode = opcode + 4'b0001;
      	#5; clock=0;
    end
  #20;
  data= data + 5'b00001; 
  end 
  end

endmodule