module fsm (BIT,RESET, CLK, STATE,count);
	input RESET,CLK,BIT;
	output STATE;// Output
	output[4:0] count;
	wire   RESET, CLK, BIT;
	reg[4:0] count;
	reg STATE;
	always @ (CLK) // This always block is to find the NextState.
     	begin
		if (RESET==1) begin
			STATE = 1'b0;
			count=1'b0;
		end
		else if(BIT==1) begin
			count = count+1;
			STATE = 1'b0;
		end
		else if(count==2 && BIT==0) begin
			STATE = 1'b1;
			count=1'b0;
		end
		else if(count==4 && BIT==0) begin
			STATE = 1'b1;
			count=1'b0;
		end
		else begin
			STATE = 1'b0;
			count = 1'b0;
		end
     	end
endmodule
	
		
	
