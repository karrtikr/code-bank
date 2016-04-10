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
	int a[10000],b[10000],c[10000],d[10000],i,j,n;
	clock_t start[4],end[4];
	double sum[4] = {0,0,0,0};
	for(i=0;i<1000;i++){
		for(j=0;j<10000;j++){
			a[j]=rand();
			b[j]=a[j];
			c[j]=b[j];
			d[j]=b[j];
		}
	// 	n = mselect(a,0,49,5,25);
	// 	printf("(%d)\n",n );
	// 		selectionsort(b,0,49);
	// for(i=0;i<50;i++)
	// 	printf("%d ",b[i]);
	// printf("(%d)\n",b[25]);
		start[0]=clock();
		n = mselect(a,0,9999,3,5000);
		end[0]=clock();
		sum[0]=sum[0]+(double)(end[0]-start[0])/CLOCKS_PER_SEC;
		// printf("(%d)\n",n );
		start[1]=clock();
		n = mselect(b,0,9999,5,5000);
		end[1]=clock();
		sum[1]=sum[1]+(double)(end[1]-start[1])/CLOCKS_PER_SEC;
		start[2]=clock();
		n = mselect(c,0,9999,7,5000);
		end[2]=clock();
		sum[2]=sum[2]+(double)(end[2]-start[2])/CLOCKS_PER_SEC;
		start[3]=clock();
		n = mselect(d,0,9999,9,5000);
		end[3]=clock();
		sum[3]=sum[3]+(double)(end[3]-start[3])/CLOCKS_PER_SEC;
	}
	for(i=0;i<4;i++){
		printf("%0.2lf ",sum[i]);
	}
	// int a[13] = {11,1,5,6,9,10,2,4,3,8,7,1,8};
	
	// int b[13] = {11,1,5,6,9,10,2,4,3,8,7,1,8},i;
	// selectionsort(b,0,49);
	// for(i=0;i<50;i++)
	// 	printf("%d ",b[i]);
	// printf("(%d)\n",b[25]);
	return 0;
}