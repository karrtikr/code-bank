`include "fsm_row.v"

module fsm_row_tb();
reg x;
reg clk;
reg reset;
wire y;

reg in[31:0];   //register for input array
integer counter;  //counter used for storing bits into array
integer i=0; //counter starts from 0th index
initial begin
  $display("time\tclock\tX\tY");
  $monitor("%g\t%b\t%b\t%b", $time, clk, x, y);
  while (i<32) begin // storing the input sequence into array
    in[i]=($random)%2;
    i=i+1;
  end
  clk = 1;
  reset = 0;
  counter = 31;
  x = in[counter]; // started with most significant bit of input
  #150 $finish;
end

always @(clk)begin   //each bit is read from the array syncing with clock
   x = in[counter];
   counter = counter - 1;
end

always begin
  #5 clk = ~clk; // The clock ticks after every 5 units of time.
end

fsm_row first(x, clk, reset, y); // Connecting the DUT
endmodule
