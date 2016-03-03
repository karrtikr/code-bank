#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void swap(int a[],int x,int y){
	int temp=a[x];
	a[x]=a[y];
	a[y]=temp;
}

int partition(int a[],int l,int r){
	if(l==r)
		return l;
	if(r==l+1){
		if(a[r]>a[l])
			return l;
		else{
			swap(a,l,r);
			return r;
		}
	}
	int x=a[l];
	int L=l+1,R=r;
	while(L!=R){
		while(a[L]<x){
			L++;
		}
		while(a[R]>x && L!=R){
			R--;
		}
		swap(a,L,R);
	}
	swap(a,l,L-1);
	return L-1;
}

void quicksort(int a[],int l,int r){
	if(l<r){
		int i;
		i=partition(a,l,r);
		quicksort(a,l,i-1);
		quicksort(a,i+1,r);
	}
}

int main(){
	int a[10000],b[10000];
	int i,n,j;
	double temp=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		// b[i]=rand()%100;
		scanf("%d",&b[i]);
	}

		for(i=0;i<n;i++){
			a[i]=b[i];
		}
		// quicksort(a,0,n-1);
		clock_t tStart = clock();
		quicksort(a,0,n-1);
		temp=temp+(double)(clock()-tStart)/CLOCKS_PER_SEC;

	temp=temp/500;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	printf("Execution Time: %.2fs\n", temp);
	return 0;
}