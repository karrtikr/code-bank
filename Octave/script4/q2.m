1;
function m = val(total)
  count = 0;
  for sample=1:total
    v = [ -1 + (2)*rand(1), -1 + (2)*rand(1) ];
    if ( v*v.' <= 1.0 )
      count=count+1;
    endif
  endfor
  m=4*count/total;
endfunction

x=[]; y=[];
n = 1e1;
while (n < 1e7)
  x(end+1)=n;
  y(end+1)=val(n);
  printf("%d %.4f\n",x(end),y(end));
  n *= 10;
endwhile
semilogx(x,y);
xlabel("Sample size");
ylabel("Value of Pi");
title("Plot for value of pi");
legend("estimated","provided in octave");
grid on;