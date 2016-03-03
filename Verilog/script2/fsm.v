module fsm (MOVE, RESET, CLK, STATE);
   // Declare the inputs as wires and outputs as registers.
   input MOVE, RESET, CLK; // Inputs
   output [2:0] STATE;// Output
   wire   MOVE, RESET, CLK;
   reg [2:0] STATE = 3'b000; // The fido starts from the Computer Center.
   parameter CC = 3'b000, Lib = 3'b001, NewSac = 3'b010, 
     CCD = 3'b011, ShopC = 3'b100, SPO = 3'b101, MT = 3'b110, FB = 3'b111;
   // These parameters make the program easier to follow.
   reg [2:0] NextState = CC; // NextState holds the value of the next state.
   
   always @ (posedge CLK) begin
      if (RESET == 1) STATE = CC; // Fido goes back to CC if RESET = 1.
      else STATE = NextState; // else it takes the next state.
   end

   always @ (*) // This always block is to find the NextState.
     begin
	if (RESET==1) NextState = CC;
	else case(NextState) // The below code is according to the 
	       // transition function given in the question.
	       CC:
		 NextState = MOVE ? Lib : CC;
	       Lib:
		 NextState = MOVE ? ShopC : NewSac;
	       NewSac:
		 NextState = MOVE ? ShopC : CCD;
	       CCD:
		 NextState = MOVE ? CC : CCD;
	       ShopC:
		 NextState = MOVE ? SPO : FB;
	       SPO:
		 NextState = MOVE ? MT : CCD;
	       MT:
		 NextState = MOVE ? MT : FB;
	       FB:
		 NextState = MOVE ? SPO : Lib;
	     endcase // case (NextState)
     end // always @ (*)
   
endmodule // fsm
