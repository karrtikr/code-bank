#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int m;
int q;
int c[1000000];
void swap(int *a, int *b ){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

// int partition(int* a,int i,int j){
//   if(i>=j) return i;
//   int idx,k=i;
//   for(idx=i+1;idx<=j;idx++){
//     if(a[idx]>=a[k]){
//       q=q+1;
//       continue;
//     }
//     else {
//       swap(a+k+1,a+idx);
//       swap(a+k,a+k+1);
//       k=k+1;
//       q=q+1;
//     }
//   }
//   return k;
// }

// void quicksort(int *a,int i, int j){
//   if(j<=i) return;
//   int k = partition(a,i,j);
//   quicksort(a,i,k-1);
//   quicksort(a,k+1,j);
// }

int partition (int arr[], int l, int h)
{
    int x = arr[h];    // pivot
    int i = (l - 1);  // Index of smaller element
    int j;
    for ( j = l; j <= h- 1; j++)
    {
        // If current element is smaller than or equal to pivot 
        if (arr[j] <= x)
        {
      //count++;
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);  // Swap current element with index
        }
    }
    swap(&arr[i + 1], &arr[h]);  
    return (i + 1);
}
 
/* arr[] --> Array to be sorted, l  --> Starting index, h  --> Ending index */
void quicksort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h); /* Partitioning index */
        quicksort(arr, l, p - 1);
        quicksort(arr, p + 1, h);
    }
}

void mergesort(int *a,int i,int j){
  if(j==i) return;
  int mid = (i+j)/2;
  mergesort(a,i,mid);
  mergesort(a,mid+1,j);
  int n = j-i+1;
  int r=i,s=mid+1,l=0;
  while(r<=mid && s<=j){
    if(a[r]<a[s]){
      c[l] = a[r];
      r++;l++;
    }
    else{
      c[l] = a[s];
      s++;l++;
    }
    m=m+1;
  }
  while(r<=mid){
    c[l] = a[r];
    r++;l++;
  }
  while(s<=j){
    c[l] = a[s];
    s++;l++;
  }
  for(l=i;l<=j;l++){
    a[l] = c[l-i];
  }
}

int main(){
  int a[1000000],b[1000000],count=0;
  int n = 100; int flag=0,i,j;
  clock_t start, end;
  double time1,time2;
  while(n<=1000000){
    for(int i=0;i<2000;i++){
      for(int j=0;j<n;j++){
	       b[j] = rand();
         a[j]=b[j];
      }
      start = clock();
      mergesort(a,0,n-1);
      end = clock();
      time2 = (double)(end-start)/CLOCKS_PER_SEC;
      start = clock();
      quicksort(b,0,n-1);
      end = clock();
      time1 = (double)(end-start)/CLOCKS_PER_SEC;
      if(time1>time2){
        count=count+1;
      }
      // printf("quick=%lf merge=%lf\n",time1,time2);
    }
    printf("n=%d Number of times Merge Sort outperformed Quick Sort=%d\n",n,count);
    count=0;
    n = n*10;
  }
  return 0;
}
