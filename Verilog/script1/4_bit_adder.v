module adder (
    input [3:0] A,
    input [3:0] B,
    output [3:0] C,
    output CF
  );
  assign {CF,C} = A + B;
  initial begin
    $monitor("%b  %b  %b  %b", A, B, C, CF);
  end
endmodule
