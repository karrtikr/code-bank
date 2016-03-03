#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double q=0;

void swap(int *a, int *b ){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

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
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);  // Swap current element with index
        }
        q++;
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
//       k = k+1;
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

int main(){
  int a[1000002];
  clock_t start, end;
  double time = 0,sq;
  int n = 100;
  while(n<=1000000){
    sq=0;
    time=0;
    for(int i=0;i<5000;i++){
      q=0;
      for(int j=0;j<n;j++){
	      a[j] = rand();
      }
      start = clock();
      quicksort(a,0,n-1);
      end = clock();
      time = time + (double)(end-start)/CLOCKS_PER_SEC;
      sq=sq+q;
    }
    time=time/5000;
    sq=sq/5000;
    printf("n = %d\ttime = %lf\tcomparisions=%.2lf\n",n,time,sq);
    n = n*10;
  }
  return 0;
}
