#include <stdio.h>
#include <stdlib.h>

int main(){
	double m,s;
	int x;
	x=3000;
	m=(180.23-0.401)/87000;
	while(x<=90000){
		s=m*(x-3000)+0.401;
		printf("%d\t%lf\n",x,s);
		x=x+3000;
	}
	return 0;
}