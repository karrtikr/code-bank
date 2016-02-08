x=0:50;
y= normpdf(x,15,sqrt(10.5));
h=[];n=10;
while(n<=1e6)
	temp=normrnd(15,sqrt(10.5),[1,n]);
	h1=hist(temp,x);
	h=[h;h1];
	n=n*10;
endwhile
save data x y h;
