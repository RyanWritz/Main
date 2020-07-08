typedef enum {  OFF, //power off
		RED, //red state
		YELLOW, //yellow state
		GREEN, //green state
		PRE_GREEN //state before green
	     }
	     	lights_t; 

module trafficlight
(
	output lights_t ns_light, //North-South light status, main road
	output lights_t	ew_light,  //East-West light status
	input ew_sensor,  	  //East-West sensor for new car
	input emgcy_sensor, 	  //emergency sensor
	input reset_n, 		  //synchronous reset
	input clk		  //master clock
); 

timeunit 1ns; 
timeprecision 100ps; 
parameter FAIL =1'b0; 

logic [1:0] ns_green_timer; //timer for NS light in GREEN
logic [1:0] ew_green_timer; //timer for EW light in GREEN
logic reset_s; 

int i = 0; 
int j = 0; 

always_comb
	begin 
		reset_s = reset_n && clk; 
	end

always_ff @(posedge clk)
	begin
		if(reset_s == 0)
			begin
				if(i!=3)
					begin
						for(i = 0; i < 3; i++)
							begin 
								ns_green_timer <= i; 
							end
					end
				 else if (i == 3)
					begin
						i = 0; 
						ns_green_timer <= 0;
					end
			end
		else if(reset_s == 1 || ns_light yellow == 1)
			begin 
				ns_green_timer <= 0; 
			end
	end

always_ff @(posedge clk)
	begin
			if (reset_s == 0)
				begin 
					if (j != 3)
						begin
							for (j = 0; j < 3; j++)
								begin
									ew_green_timer <= j; 
								end	
						end		
					else if (j == 3)
						begin 
							j = 0; 
							ew_green_timer <= j; 
						end
				end
			else if(reset_s == 1 || ew_light yellow == 1)
				begin
					ew_green_timer <= 0; 
				end 
	end

always_ff @(posedge clk)
	begin
		if(ew_sensor == 0 && emgcy_sensor ==0)
			begin
				ns_light red <= 0; 
				ns_light pre_greem <= 0; 
				ns_light yellow <= 0; 
				ns_light off <= 0; 
				ns_light green <= 1; 
				ew_light red <= 1; 
				ew_light pre_greem <= 0; 
				ew_light yellow <= 0; 
				ew_light off <= 0; 
				ew_light green <= 0; 
			end
		else if(ns_light green == 1 && emgcy_sensor==1)
			begin 
				ns_light red <= 0; 
				ns_light pre_greem <= 0; 
				ns_light yellow <= 1 
				ns_light off <= 0; 
				ns_light green <=0; 
				ew_light red <= 1; 
				ew_light pre_greem <= 0; 
				ew_light yellow <= 0; 
				ew_light off <= 0; 
				ew_light green <= 0; 
			end
		else if(ew_light pre_green == 1)
			begin
				for(ew_green_timer = ew_green_timer + 1)
					begin 
						ew_light green <= 1
					end
			end
		else if (ew_light yellow == 1)
			begin 
				ew_light yellow = 0; 
				ew_light red == 1;
			end
	end



		
	

endmodule		
