`include "serial_parity.v"

module serial_parity_tb();
// declare the inputs as registers and outputs as wires.
reg x;
reg clk;
wire p;
   
initial begin
  $display("time\tclock\tX\tParity");
  $monitor("%g\t%b\t%b\t%b", $time, clk, x, p); // printig the values.  
  clk = 1;
  x = {$random}%2; //initial values of clk and x.
  #100 $finish; // The simulation stops after 100 units of time.
end

always @(posedge clk)begin
   x = {$random}%2; // giving input bits in synchronization with the clock.
end

always begin
  #5 clk = ~clk; // The clock value changes after every 5 units of time.
end

serial_parity first(x, clk, p); // connecting the DUT.

endmodule
