`include "fsm.v"

module test();
   reg reset, move, clk;
   wire [2:0] state;

   initial begin
      $display ("Reset\tclock\tMove\tState");
      $monitor ("%b\t%b\t%b\t%b",
		reset, clk, move, state);
      reset = 1'b0;// Setting the initial values of the variables.
      move = 1'b1;
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
      move = ~move; // Move changes along with the clock.
   end

   fsm instantiate_instance(move, reset, clk, state); // Connecting the DUT.

endmodule //
