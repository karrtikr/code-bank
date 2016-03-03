#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double m=0;
int c[1000000];

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
  int a[1000002];
  clock_t start, end;
  double time2 = 0,sm=0;
  int n = 100;
  while(n<=1000000){
    sm=0;
    time2=0;
    for(int i=0;i<5000;i++){
      m=0;
      for(int j=0;j<n;j++){
         a[j] = rand() % 1000;
      }
      start = clock();
      mergesort(a,0,n-1);
      end = clock();
      time2 = time2 + (double)(end-start)/CLOCKS_PER_SEC;
      sm=sm+m;
    }
    time2=time2/5000;
    sm=sm/5000;
    printf("n = %d\ttime = %lf\tcomparisions=%.2lf\n",n,time2,sm);
    n = n*10;
  }
  return 0;
}
