#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int IFib(long long int n){
	int a=0,b=1,temp;
	long long int i;
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	for(i=2;i<=n;i++){
		temp=b;
		b=(a+b)%2014;
		a=temp;
	}
	return b;
}

int main() 
{
	clock_t start,end;
	long long int n;
	scanf("%lld",&n);
	start=clock();
	printf("%d\n",IFib(n));
	end=clock();
	double t=(double)(end-start)/CLOCKS_PER_SEC;
	printf("%lf\n",t);
	return 0;
}