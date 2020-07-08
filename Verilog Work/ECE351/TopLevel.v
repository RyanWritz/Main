module TopLevel(
    input [15:0]sw,                         //Switch controls
    output [15:0]led,
    input clk,                              //Onboard 100 Mhz Clock 
    input btnD,                             //Onboard button to create clock pulse  
    output [6:0]seg,				        //Seven segment display cathode pins   
	output dp, 
	output [7:0]an,      					//Seven segment display anode pins
	input btnCpuReset	                    //red pushbutton input 
);

//Variables Onboard
wire sysclk;							    // 100MHz clock from on-board oscillator
wire sysreset;						        // system reset signal - asserted high to force reset
wire [7:0]decpts = {7'b0000000,clk_1Hz};	// dp0 is toggled by clk_100Hz   
wire [7:0]SegDisp;				            // seven segment display segments  
wire clk_1Hz;					        	// 1HZ clock to drive the counter
wire [3:0]count_out;                        // 4-bit decade counter output  
wire [15:0]LED;
	
// global assigns
assign btn = btnD;
assign	sysclk = clk;  
assign dp = SegDisp[7];				    	// multiplexed decimal points and segments 
assign seg = SegDisp[6:0];					// produced by the Seven Segment display driver	 
assign 	sysreset = btnCpuReset;			// btnCpuReset is asserted low	 
assign LED = led;               
assign LED[4:0]= SWdb[4:0];
assign LED[6:5]= SWdb[6:5];
assign LED[10:7]= SWdb[10:7];
assign LED[15:11]=SWdb[15:11];


//barrelshift I/O 
wire [4:0]Q;
wire [4:0]D; 
wire [1:0]S; 
wire [3:0]Op;
wire [5:0]dbtn;

//inputs to LCD Display 
wire [3:0]OneDD;
wire [3:0]TenDD;
wire [3:0]OneDQ;
wire [3:0]TenDQ;  
wire [3:0]OneDOp;
wire [3:0]TenDOp;


wire [15:0] SWdb; 

debounce U1(	
		.clk(clk), 
		.pbtn_in({btnCpuReset,btnC,btnU,btnL,btnR,btnD}), 
		.switch_in(sw),
		.pbtn_db(dbtn), 
		.swtch_db(SWdb));

barrelshift U2(
		.Q(Q),
        .D(SWdb[4:0]),
        .S(SWdb[6:5]), 
		.Op(SWdb[10:7]), 
        .clk(dbtn[0]));

BCD U3(                             //Data BCD convereter
        .OneD(OneDD),
        .TenD(TenDD),
        .In(SWdb[4:0])); 
 
BCD U4(                             //Output BCD Converter
        .OneD(OneDQ),
        .TenD(TenDQ),
        .In(Q));
        
BCD U5(                             //Op COde BCD Converter 
        .OneD(OneDOp),
        .TenD(TenDOp),
        .In(SWdb[10:7])); 
 
sevensegment U6(
		.d0(OneDQ),
		.d1(TenDQ),
		.d2(OneDD),
		.d3(TenDD),
		.d4({3'b000,SWdb[6:5]}),
		.d5(OneDOp), 
		.d6(TenDOp),
		.dp(8'b0000_0000), 
		.seg({dp,SegDisp[6:0]}),			
		.an(an), 
		.clk(sysclk), 
		.reset(sysreset), 
		.digits_out());                     // ouput for simulation only
		 
 
endmodule