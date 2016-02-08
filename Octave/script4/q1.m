1;
function x = val(total)
  count = 0;
  for sample=1:total
    v = [ -1 + (2)*rand(1), -1 + (2)*rand(1) ];
    if ( v*v.' <= 1.0 )
      count++;
    endif
  endfor
  x=4*count/total;
endfunction
 
n = 1e1;
f=fopen("output1.txt","w");
while (n < 1e7)
  fprintf(f,"%d %.4f\n",n,val(n));
  n *= 10;
endwhile