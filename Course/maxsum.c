#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[100],i,j,im,jm,sum,sump,maxsum,n,jp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	i=0;j=0;sum=0;sump=0;maxsum=-10000;
	while(j<n){
		if(a[j]>0){
			sum=sum+a[j];
			jp=j;			//sump stores the last possible sum where a[j] was positive and jp stores that j
			sump=sum;
			if(sump>maxsum){
				im=i;
				jm=jp;
				maxsum=sump;
			}
		}
		else if(sum+a[j]<0){
			if(sump>maxsum){
				im=i;
				jm=jp;
				maxsum=sump;
			}
			i=j+1;
			sum=0;
		}
		else{
			sum=sum+a[j];
		}
		printf("%d sum=%d maxsum=%d\n",j+1,sum,maxsum);
		j=j+1;
	}
	printf("maxsum=%d i=%d j=%d\n",maxsum,im,jm);
	return 0;
}
