#include <stdio.h>
#include <stdlib.h>

int** mult(int **a,int **b){
	int i,j,k,sum;
	int **c;
	for (i=0;i<2;i++)
         c=(int**)malloc(2*sizeof(int*));
    for (i=0;i<2;i++)
         c[i]=(int*)malloc(2*sizeof(int));
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			sum=0;
			for(k=0;k<2;k++){
				sum=(sum+(a[i][k]*b[k][j])%2014)%2014;
			}
			c[i][j]=sum;
		}
	}
	return c;
}

int** power(int **a,long long int n){
	if(n==1){
		return a;
	}
	else if(n%2==1){
		int **t;
		t=power(a,n/2);
		t=mult(t,t);
		t=mult(t,a);
		return t;
	}
	else{
		int **t;
		t=power(a,n/2);
		t=mult(t,t);
		return t;
	}
}

int CleveralgoFib(long long int n){
	if(n==1)
		return 0;
	int **a;int i;
	for (i=0;i<2;i++)
         a=(int**)malloc(2*sizeof(int*));
    for (i=0;i<2;i++)
         a[i]=(int*)malloc(2*sizeof(int));
	int** b;
	a[0][0]=1;a[1][0]=1;a[1][1]=0;a[0][1]=1;
	b=power(a,n-1);
	return b[0][0];
}

int main() 
{
	long long int n;
	int x;
	scanf("%lld",&n);
	x=CleveralgoFib(n);
	printf("%d\n",x);
	return 0;
}