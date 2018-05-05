#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main(){
      int n ; scanf("%d",&n);
      int arr[n];
      for(int i=0;i<n; i++) scanf("%d",&arr[i]);
      sort(arr,arr+n);
      int diff = arr[n-1]-arr[0];
      printf("%d ",diff);
      if(diff == 0) printf("%lld\n",1ll*n*(n-1)/2);
      else{
         int mx=0,mn=0;
         int j=n-1;
         while(arr[j] == arr[n-1]){mx++;j--;}
         j=0;
         while(arr[j] == arr[0]){mn++;j++;}
         printf("%lld\n",1ll*mx*mn);
      }
      return 0 ;
}