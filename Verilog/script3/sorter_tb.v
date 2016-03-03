`include "sorter.v"

module sorter_test();
   // Declare inputs as registers and outputs as wires
   reg [11:0] weight [0:6] ; // array for input weights
   reg 	      reset;
   reg [11:0] in; //This is the input given to sorter 
   reg 	      clk;
   wire [7:0] grp [0:5]; //This contains the group count. grp[0] contains group count of grp1 and so on
   wire [2:0] currgrp;

   initial begin
      $display ("Time\tReset\tClock\tWeight\tGrp1\tGrp2\tGrp3\tGrp4\tGrp5\tGrp6\tCurrGrp");
      $monitor ("%g\t%b\t%b\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d",
		$time,reset,clk,in,grp[0],grp[1],grp[2],grp[3],grp[4],grp[5],currgrp);

      // Initialising the weight array
      weight[0] = 12'd250;weight[1] = 12'd0;weight[2] = 12'd300;
      weight[3] = 12'd0;weight[4] = 12'd501;weight[5] = 12'd512;
      weight[6] = 12'd2001;
      
      reset = 1;
      clk = 1;
      #10 reset = 0;
      //Changing the values of the input using the values stored in the array
      #20 in = weight[0];
      #30 in = weight[1];
      #25 in = weight[2];
      #20 in = weight[3];
      #25 in = weight[4];
      #10 in = weight[5];
      #20 in = weight[6];
      #10 reset = 1;
      #20 $finish; // Ending the simulation
   end


   always begin
     #5 clk = ~clk; // Clock ticks after every 5 units of time
   end

   //Connecting DUT to the testbench
   sorter first(in,clk,reset,grp[0],grp[1],grp[2],grp[3],grp[4],grp[5],currgrp);
   

endmodule // sorter_test
