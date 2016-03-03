module fsm_row(input x, input clk, input reset, output y);
// Declare the inputs as wires and outputs as registers.
reg y;
wire x,clk,reset;
reg [2:0] state = 3'b000; //initial state
parameter ZERO = 3'b000, ONE = 3'b001, TWO = 3'b010, THREE = 3'b011,   //states for no. of 1's seen in a row
        FOUR = 3'b100, MORE = 3'b101;

// This always block is used to get the output by reading each bit and using the previous state
always @(x or reset or clk)
  begin
    if(reset == 1) begin
      state = 3'b000;
    end
    else if(reset == 0 && x == 1'b0) begin
    // change of states if 0 is encountered
      case(state)
        ZERO:
        y = 1'b0;
        ONE:
        y = 1'b0;
        TWO:
        y = 1'b1;
        THREE:
        y = 1'b0;
        FOUR:
        y = 1'b1;
        MORE:
        y = 1'b0;
        endcase
        state = ZERO;
    end
    else begin
    // change of states if 1 is encountered
      y = 1'b0;
      case(state)
        ZERO:
        state = ONE;
        ONE:
        state = TWO;
        TWO:
        state = THREE;
        THREE:
        state = FOUR;
        FOUR:
        state = MORE;
        MORE:
        state = MORE;
        endcase
      end
  end
endmodule
