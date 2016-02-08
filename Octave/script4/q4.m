#!/usr/bin/octave -qf

load data;

for i = 2:7
  temp = h(i-1,:);
  figure(i-1);
  hold on;
  bar(x,temp,'b');
  plot(x,temp,'linewidth',1,'r');
  xlabel('x values','fontsize',14);
  ylabel('y values','fontsize',14);
  title('Histogram');
  hold off;
endfor
