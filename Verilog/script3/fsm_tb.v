`include "fsm.v"

module test();
   reg reset, BIT, clk;
   wire state;
   wire [4:0] count;

   initial begin
      $display ("Reset\tClock\tBit\tCount\tState");
      $monitor ("%b\t%b\t%b\t%d\t%b",
		reset, clk, BIT,count,state);
      reset = 1'b0;// Setting the initial values of the variables.
      BIT = 1'b1;
      clk = 1'b0;
      #5 reset = 1'b1;
      #10 reset = 1'b0;
      #150 reset = 1'b1;
      #5 $finish;
   end

   always begin
      #5 clk = ~clk; // The clock ticks after every 5 units of time.
   end

   always @ (posedge clk) begin
      BIT = {$random}%2; // Move changes along with the clock.
   end

   fsm instantiate_instance(BIT, reset, clk, state,count); // Connecting the DUT.

endmodule //
