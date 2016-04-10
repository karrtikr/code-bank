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

void median(int a[],int* m,int start,int end,int size){
	int b[size],i=0,j=0,x;
	while(end>=start){
		if(i==size){
			selectionsort(b,0,size-1);
			x=b[size/2];
			m[j]=x;
			j++;
			i=0;
		}
		b[i]=a[start];
		i++;
		start++;
	}
	if(i!=0){
		selectionsort(b,0,i-1);
		x=b[i/2];
		m[j]=x;
	}
}

int mselect(int a[],int start,int end,int size,int i){
	if(start==end){
		return a[start];
	}
	int len,r,x,s;
	int* m;
	s=(end-start+1)%size;
	if(s!=0)
		len=(end-start+1)/size+1;
	else
		len=(end-start+1)/size;
	m = (int *)malloc(len*sizeof(int));
	median(a,m,start,end,size);
	// for(i=0;i<len;i++){
	// 	printf("%d ",m[i]);
	// }
	x=mselect(m,0,len-1,size,len/2);
	// printf("\nx=%d",x);
	r=partition(a,start,end,x);
	if(i==r)
		return x;
	else if(i<r)
		return mselect(a,start,r-1,size,i);
	else
		return mselect(a,r+1,end,size,i-r);
}

int main(){
	int a[100000],i,j,n,size;
	FILE *fp;
	clock_t start,end;
	double sum = 0;
	fp = fopen("output.txt","w");
	for(size=1;size<=100;size++){
		size++;size++;
		for(i=0;i<1000;i++){
			for(j=0;j<1000*size;j++){
				a[j]=rand();
			}
			start=clock();
			n = mselect(a,0,1000*size-1,9,500*size);
			end=clock();
			sum=sum+(double)(end-start)/CLOCKS_PER_SEC;
		}
		printf("%d\t%0.2lf\n",1000*size,sum);
		fprintf(fp,"%d\t%0.2lf\n",1000*size,sum);
	}
	fclose(fp);
	return 0;
}