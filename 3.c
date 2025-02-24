#include<stdio.h>
#include<time.h>
void swap(int *a,int *b)
{
 int temp=*a;
  *a=*b;
  *b=temp;
}
int partition(int a[],int low,int high)
{
 int p=a[low];
 int i=low+1;
 int j=high;
 while(i<=j)
 {
   while(i<=high && a[i]<=p)
   {
      i++;
    }
   while(a[j]>p)
   {
      j--;
   }
   if(i<j)
   {
      swap(&a[i],&a[j]);
    }
   }
   swap(&a[low],&a[j]);
   return j;
}
void quicksort(int a[],int low,int high)
{
 if(low<high)
 {
   int pi=partition(a,low,high);
   quicksort(a,low,pi-1);
   quicksort(a,pi+1,high);
  }
  
}
void main()
{
 int i,n;
 printf("Enter the number of elements:");
 scanf("%d",&n);
 int a[n];
 srand(time(NULL));
 for(i=0;i<n;i++)
 {
   a[i]=rand()%1000000;
   
 }
 
 
 clock_t start=clock();
 quicksort(a,0,n-1);
 clock_t end=clock();
 double t=((double)(end-start))/CLOCKS_PER_SEC;
 printf("Time taken is %fs",t);
 /*printf("Sorted array:");
 for(i=0;i<n;i++)
 {
   printf("%d\t",a[i]);
  }*/
  
} 
 
