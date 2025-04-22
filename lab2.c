#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[],int low,int mid,int high)
{
int i=low,j=mid+1,k=low;
int c[1000000];
while(i<=mid&&j<=high){
if(a[i]<a[j]){
c[k]=a[i];
i++;
}
else
{
c[k]=a[j];
j++;
}
k++;
}
while(i<=mid)
{
c[k++]=a[i++];
}
while(j<=high)
{
c[k++]=a[j++];
}
for(i=low;i<=high;i++)
{
a[i]=c[i];
}
}
void mergesort(int a[],int low,int high)
{
if(low<high)
{
int mid=(low+high)/2;
mergesort(a,low,mid);
mergesort(a,mid+1,high);
merge(a,low,mid,high);
}
}
int main()
{
int n;
printf("enter the number of elemnts:");
scanf("%d",&n);
int arr[n];
srand(time(NULL));
int i;
for(i=0;i<n;++i)
{
arr[i]=rand()%100000;
}
clock_t start=clock();
mergesort(arr,0,n-1);
clock_t end=clock();
printf("sorted array is:");
for(i=0;i<10;i++)
printf("%d ",arr[i]);
double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
printf("Time taken for sorting:%f seconds\n",time_taken);
return 0;
}