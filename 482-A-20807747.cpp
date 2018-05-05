#include <bits/stdc++.h>
using namespace std;
typedef long double ld ;

int main(){

   int n,k ; scanf("%d%d",&n,&k);
   int arr[n] ;
   arr[n-k] = n ;
   for(int i=0 ; i< n-k ; i++){
      arr[i] = i+1 ;
   }
   int d = n-arr[n-k-1]-1;
   int f = -1 ;
   for(int i=n-k+1 ; i<n ; i++){
       arr[i] = arr[i-1]+(d*f);
       d-- ;
       f *= -1 ;
   }

   for(int i=0 ; i<n ; i++){
      printf("%d%s",arr[i],(i==n-1)?"\n":" ");
   }
   return 0 ;
 }