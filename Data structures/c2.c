#include<stdio.h>
#include<time.h>

int IFib(long long int n){
	int a=0,b=1,temp,i;
	if(n==1)
		return 0;
	else if(n==2)
		return 1;
	for(i=2;i<n;i++){
		temp=b;
		b=(a+b)%2014;
		a=temp;
	}
	return b;
}

int main() 
{
	long long int n;
	int x;
	scanf("%lld",&n);
	x=IFib(n)%2014;
	printf("%d\n",x);
	return 0;
}