#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void merge(int [],int ,int ,int );
void mergeSort(int [],int ,int );

int main(){
    int n ,size ,i,count = 0;
    long long sum = 0;
    scanf("%d %d",&n,&size);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

   mergeSort(arr,0,n-1);
   for(i=n-1;i>=0;i--){
        sum += arr[i];
        count ++;
      if(sum >= size) break;
   }
   printf("%d\n",count);
return 0;
}

void mergeSort(int arr[],int min,int max)
{
 int mid;
 if(min<max)
 {
   mid=(min+max)/2;
   mergeSort(arr,min,mid);
   mergeSort(arr,mid+1,max);
   merge(arr,min,mid,max);
 }
}


void merge(int arr[],int min,int mid,int max)
{
  int tmp[100000];
  int i,j,k,m;
  j=min;
  m=mid+1;
  for(i=min; j<=mid && m<=max ; i++)
  {
     if(arr[j]<=arr[m])
     {
         tmp[i]=arr[j];
         j++;
     }
     else
     {
         tmp[i]=arr[m];
         m++;
     }
  }
  if(j>mid)
  {
     for(k=m; k<=max; k++)
     {
         tmp[i]=arr[k];
         i++;
     }
  }
  else
  {
     for(k=j; k<=mid; k++)
     {
        tmp[i]=arr[k];
        i++;
     }
  }
  for(k=min; k<=max; k++)
     arr[k]=tmp[k];
}