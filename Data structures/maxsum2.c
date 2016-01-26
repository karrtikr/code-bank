#include <stdlib.h>
#include <stdio.h>

int main(){
	int a[100],i,s[100],x[100],y,max,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	s[0]=a[0];x[0]=0;y=0;
	for(i=1;i<n;i++){
		if(s[i-1]>0)
		{
			x[i]=x[i-1];
			s[i]=s[i-1]+a[i];
		}
		else
		{
			s[i]=a[i];
			x[i]=i;
		}
		max=s[i]>s[i-1]?s[i]:s[i-1];
		y=s[i]>s[i-1]?i:y;
	}
	printf("(%d,%d) %d\n",x[y],y,max);
}