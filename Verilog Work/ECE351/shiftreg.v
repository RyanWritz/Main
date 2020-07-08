module shiftreg(Q,D,clk,reset,direct,type);  
    parameter Width=5;

    output [Width-1:0]Q; 
    reg [Width-1:0]Q;
    input [Width-1:0]D;
    reg [Width-1:0]D;
    input clk,reset,direct,type;
    
    always@(posedge clk or posedge reset)
        begin
            if(reset)                                   //If Reset
                Q=5'b0_0000;
            else if(direct==1'b0 && type==1'b0)         //Left logical shift
            	Q=D<<1;    
            else if(direct==1'b0 && type==1'b1)         //Left arithmetic shift        
                Q=D<<<1; 
            else if(direct==1'b1 && type==1'b0)         //Right logical shift
                Q=D>>1; 
            else         				//Right arithemetic shift 
                Q=D>>>1;
 
        end

endmodule 
 