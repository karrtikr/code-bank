module serial_parity(input x, input clk, output p);//x is the input bit.
                                            //p is the parity.
reg p;

initial begin
  p = 1'b0;//initial parity is even.
end

always @(x or clk) //both clock and input are in synchronization. 
  // It makes no difference if we take one of them or both them here.
  begin //The functionality of the module.
    if(p == 1'b0) begin 
       //if parity is even and we receive a 1 parity becomes odd
      p = x ? 1 : 0;
    end
    else begin
       //if parity is odd and we receive a 1 parity becomes even
      p = x ? 0 : 1;
    end
  end
endmodule


