#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main(){
   int n , m ;
   scanf("%d%d",&n,&m);
   int a[n+1]; a[0] = 0;
   int arr[n] ;
   scanf("%d",&arr[0]);
   for(int i=1 ; i<n ; i++){
      scanf("%d",&arr[i]);
      a[i] = (arr[i]==arr[i-1]) ? a[i-1] : i ;
   }
   int l,r,j ,index;
   for(int i=0 ; i<m ; i++){
    scanf("%d%d%d",&l,&r,&j);
    if(arr[r-1] != j)  index = r ;
    else if(a[r-1] < l) index = -1 ;
    else index = a[r-1] ;
    printf("%d\n",index);
   }
   return 0 ;
}