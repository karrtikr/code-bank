module adder_tb();
  reg [3:0] A, B;
  wire [3:0] C;
  wire CF;
  adder  first_instance (
    .A(A),
    .B(B),
    .C(C),
    .CF(CF)
  );

  initial begin
    $display(" A     B     C   CF");
    A = 4'b0000;
    B = 4'b0000;
    #10
    A = 4'b1111;
    B = 4'b0101;
    #10
    A = 4'b1100;
    B = 4'b1111;
    #10
    A = 4'b1100;
    B = 4'b0011;
    #10
    A = 4'b0100;
    B = 4'b1011;
    #10
    A = 4'b1110;
    B = 4'b0000;
    #10
    A = 4'b1011;
    B = 4'b0001;
    #10
    A = 4'b0110;
    B = 4'b1111;
    #10
    A = 4'b0101;
    B = 4'b1011;
    #10
    A = 4'b1111;
    B = 4'b1111;
    #10
    $finish;
  end
endmodule
