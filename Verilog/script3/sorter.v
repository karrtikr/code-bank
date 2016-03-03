module sorter(weight,clk,reset,grp1,grp2,grp3,grp4,grp5,grp6,currgrp);
   
   input clk,reset;
   input [11:0] weight;
   output [7:0] grp1,grp2,grp3,grp4,grp5,grp6;
   output [2:0] currgrp;

   //Declare inputs as wires and outputs as registers
   wire 	clk,reset;
   wire [11:0] 	weight;
   reg [7:0] 	grp1,grp2,grp3,grp4,grp5,grp6;
   reg [2:0] 	currgrp;
   reg [12:0] 	total; // This holds the total weight(when object is not "new")
   reg [11:0] 	lastweight; // This holds the previous value of weight
   
   always @ (negedge clk or reset) begin
      if (reset) begin // If reset is 1 all values are set to zero
	 grp1 = 0;
	 grp2 = 0;
	 grp3 = 0;
	 grp4 = 0;
	 grp5 = 0;
	 grp6 = 0;
	 currgrp = 3'b0;
	 lastweight = 0;
	 total = 0;
      end
      
      else begin
	 if ((lastweight==0) && (weight!=0)) begin // This is the case of a "new" object
	    if(weight>=12'd1 && weight<=12'd200) begin //First category from 0 to 200 grams
	       grp1=grp1+1;
	       currgrp = 3'd1;
	    end
	    else if(weight>=12'd201 && weight<=12'd500) begin //Second groupfrom 201 to 500
	       grp2=grp2+1;
	       currgrp = 3'd2;
	    end
	    else if(weight>=12'd501 && weight<=12'd800) begin //Third group from 501 to 800
	       grp3=grp3+1;
	       currgrp = 3'd3;
	    end
	    else if(weight>=12'd801 && weight<=12'd1000) begin // Fourth group from 801 to 1000
	       grp4=grp4+1;
	       currgrp = 3'd4;
	    end
	    else if(weight>=12'd1001 && weight<=12'd2000) begin // Fifth group from 1001 to 2000
	       grp5=grp5+1;
	       currgrp = 3'd5;
	    end
	    else begin // Sixth group above 2000
	       grp6=grp6+1;
	       currgrp = 3'd6;
	    end
	    lastweight = weight; //update lastweight
	    total = weight;//update total weight
	    
	 end // if ((lastweight==0) && (weight!=0))

	 else if((lastweight!=0) && (weight!=lastweight)) begin // This is the case when the object is not new
	                                                        // We only have to update the curr grp and not the grp count
	    total = total+weight; //update total weight
	    lastweight = weight; // update last weight
	    if (weight==0) begin //In case the weight is taken away currgrp = 0 and total weight = 0
	       currgrp = 0;
	       total = 0;
	    end
	    // Otherwise update currgrp according to total weight
	    else if (total>0 && total<=13'd200) currgrp = 3'd1;
	    else if (total<=13'd500) currgrp=3'd2;
	    else if (total<=13'd800) currgrp=3'd3;
	    else if (total<=13'd1000) currgrp=3'd4;
	    else if (total<=13'd2000) currgrp = 3'd5;
	    else if (total>13'd2000) currgrp = 3'd6;
	 end
      end
   end
endmodule // sorter
