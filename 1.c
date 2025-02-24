#include<stdio.h>

#include<time.h>

void main()

{

 int i,n,j,min,temp;

 printf("Enter the number of elements:\n");

 scanf("%d",&n);

 int a[n];

 printf("Enter %d elements\n",n);

 srand(time(NULL));

 for(i=0;i<n;i++)

 {

   a[i]=rand()%25000;

 }

 clock_t start=clock();

 for(i=0;i<n;i++)

 {

   min=i;

   for(j=i+1;j<n;j++)

   {

      if(a[j]<a[min])

      {

         temp=a[min];

         a[min]=a[j];

         a[j]=temp;

      }

   }

 }

 clock_t end=clock();

 double t=((double)(end-start))/CLOCKS_PER_SEC;

 //printf("Sorted array is:\n");

 //for(i=0;i<n;i++)

 //{

  //printf("%d\t",a[i]);

 //}

 printf("Time taken is %F ",t);

}

     
