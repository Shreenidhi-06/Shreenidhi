#include<stdio.h>
#define MAX_ITEMS 100
double computeMaxValue(double W,double weight[],double value[],double ratio[],int nitems);
int getNextitem(double weight[],double value[],double ratio[],int nitems);
int main()
{
int i;
int nitems;
double W;
double weight[MAX_ITEMS];
double value[MAX_ITEMS];
double ratio[MAX_ITEMS];
printf("enter the number of items:");
scanf("%d",&nitems);
printf("enter the weights of the items:\n");
for(i=0;i<nitems;i++)
{
scanf("%lf",&weight[i]);
}
printf("enter the values/profits of items\n");
for(i=0;i<nitems;i++)
{
scanf("%lf",&value[i]);
}
for(i=0;i<nitems;i++)
{
ratio[i]=value[i]/weight[i];
}
printf("enter the capacity of the knapSack:");
scanf("%lf",&W);
printf("\n the maximum value in a knapsack of capacity %2f is: %2f\n",W,computeMaxValue(W,weight,value,ratio,nitems));
return 0;
}
double computeMaxValue(double W,double weight[],double value[],double ratio[],int nitems)
{
double cW=0;
double cV=0;
printf("\n items considered are:");
while(cW<W)
{
int item=getNextitem(weight,value,ratio,nitems);
if(item==-1)
{
break;
}
printf("%d",item+1);
if(cW+weight[item]<=W)
{
cW+=weight[item];
cV+=value[item];
ratio[item]=0;
}
else
{
cV+=(ratio[item]*(W-cW));
cW+=(W-cW);
break;
}
}
return cV;
}
int getNextitem(double weight[],double value[],double ratio[],int nitems)
{
double highest=0;
int index=-1;
int i;
for(i=0;i<nitems;i++)
{
if(ratio[i]>highest)
{
highest=ratio[i];
index=i;
}
}
return index;
}

