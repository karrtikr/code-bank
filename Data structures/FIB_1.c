#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int RFib(long long int n){
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else
		return (RFib(n-1)+RFib(n-2))%2014;
}

int main() 
{
	clock_t start,end;
	long long int n;
	scanf("%lld",&n);
	start=clock();
	printf("%d\n",RFib(n));
	end=clock();
	double t=(double)(end-start)/CLOCKS_PER_SEC;
	printf("%lf\n",t);
	return 0;
}