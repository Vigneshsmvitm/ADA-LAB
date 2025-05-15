#include<stdlib.h>
#include<stdio.h>
#define MAX_ITEMS 100
double computeMaxvalue(double w,double weight[],double value[],double ratio[],int nitems)
{
 double cw=0;
 double cv=0;
 printf("\nItems considered are: \t");
 while(cw<w)
 {
	int item=getNextItem(weight,value,ratio,nitems);
	if(item==-1)
	{
		break;
	}
	printf("%d",item+1);
	if(cw+weight[item]<=w)
	{
		cw+=weight[item];
		cv+=value[item];
		ratio[item]=0;
	}
	else
	{
		cv+=(ratio[item]*(w-cw));
		cw+=(w-cw);
		break;
	}
 }
 return cv;
}
int getNextItem(double weight[],double value[],double ratio[],int nitems)
{
 int i;
 double highest=0;
 int index=-1;
 for(i=0;i<nitems;i++)
{
	if(ratio[i]>highest)
	{
		highest+=ratio[i];
		index=i;
	}
 }
 return index;
}
int main()
{
 int i;
 int nitems;
 double w;
 double weight[MAX_ITEMS];
 double ratio[MAX_ITEMS];
 double value[MAX_ITEMS];
 printf("Enter the number of items");
 scanf("%d",&nitems);
 printf("Enter the weight of the matrix\n");
 for(i=0;i<nitems;i++)
 {
	scanf("%lf",&weight[i]);
 }
 printf("Enter the value/profit of the items\n");
 for(i=0;i<nitems;i++)
 {
	scanf("%lf",&value[i]);
 }
 for(i=0;i<nitems;i++)
 {
 	ratio[i]=value[i]/weight[i];
 }
 printf("Enter the capacity of the knapsack");
 scanf("%lf",&w);
printf("\nThe minimum value in a knapsack of capacity %0.2f is %2f\n",w,computeMaxvalue(w,weight,value,ratio,nitems));
return 0;
}
