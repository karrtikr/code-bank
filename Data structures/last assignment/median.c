#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void selectionsort(int *a,int i,int j){
	if (j<=i) return;
	int min = a[i];
	int idx = i;
	for (int k=i;k<=j;k++){
		if (a[k]<min){
			min = a[k];
			idx = k;
		}
	}
	swap(a+i,a+idx);
	selectionsort(a,i+1,j);
}

int smallarraymed(int *a,int i,int j){
	int *p;
	p = (int*)malloc((j-i+1)*sizeof(int));
	for(int k=i;k<=j;k++){
		p[k-i] = a[k];
	}
	selectionsort(p,0,j-i);
	int c = p[(j-i+1)/2];
	free(p);
	return c;
}

int partition (int *a, int l, int h, int x){
	int m = l;
	while(a[m]!=x) m++;
	swap(&a[m],&a[h]);
    int i = (l - 1);
    int j;
    for ( j = l; j <= h-1; j++){
        if (a[j] <= x){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[h]);  
    return (i + 1);
}

int mselect(int *a,int i, int j,int k, int size){
	printf("Executing mselect arr=a i=%d j=%d k=%d\n",i,j,k );
	for(int m=i;m<=j;m++){
		printf("%d ",a[m]);
	}
	printf("\n");
	if(i==j && j==k) {
		printf("Completed mselect arr=a i=%d j=%d k=%d\n",i,j,k );
		return a[i];
	}

	int *b;
	int x;
	int n = j-i+1;
	if(n%size!=0){
		int d = n/size+1;
	//printf("1\n");
		b = (int *)malloc(d*sizeof(int));
	//printf("2\n");
		for (int l=0;l<d-1;l++){
			b[l] = smallarraymed(a,i+l*size,i+(l+1)*size-1);
		}
	//printf("3\n");
		b[d-1] = smallarraymed(a,i+(d-1)*size,j);
	//printf("4\n");
	//free(b);
		printf("Going for mselect i=0 j=%d k=%d\n",d-1,(d-1)/2);
		x = mselect(b,0,d-1,(d-1)/2,size);
	}
	else{
		int d = n/size;
	//printf("1\n");
		b = (int *)malloc(d*sizeof(int));
	//printf("2\n");
		for (int l=0;l<d;l++){
			b[l] = smallarraymed(a,i+l*size,i+(l+1)*size-1);
		}
	//printf("3\n");
		//b[d-1] = smallarraymed(a,i+(d-1)*size,j);
	//printf("4\n");
	//free(b);
		printf("Going for mselect i=0 j=%d k=%d\n",d-1,(d-1)/2);
		x = mselect(b,0,d-1,(d-1)/2,size);
	}
	printf("1\n");
	int pivot = partition(a,i,j,x);
	printf("pivot = %d",pivot);
	printf("2\n");
	int stat;
	if(pivot==k) {
		stat = a[pivot];
	}
	else if(pivot<k) {
		stat = mselect(a,pivot+1,j,k,size);
	}
	else {
		stat = mselect(a,i,pivot+1,k,size);
	}
	printf("Completed mselect arr=a i=%d j=%d k=%d\n",i,j,k );
	return stat;
}

int main(){
	int a[11] = {11,1,5,6,9,10,2,4,3,8,7};
	int n = mselect(a,0,10,2,3);
	printf("(%d)\n",n );
	return 0;
}