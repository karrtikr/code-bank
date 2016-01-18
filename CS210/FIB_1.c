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
	long long int n;
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%lld",&n);
		printf("%d\n",RFib(n));
	}
	return 0;
}
