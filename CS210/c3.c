#include<stdio.h>
#include<time.h>

int RFib(long long int n){
	if(n==1)
		return 0;
	else if(n==2)
		return 1;
	else
		return (RFib(n-1)+RFib(n-2))%2014;
}

int main() 
{
	long long int n;
	int x;
	scanf("%lld",&n);
	x=RFib(n)%2014;
	printf("%d\n",x);
	return 0;
}