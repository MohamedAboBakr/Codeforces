#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <stdio.h>
#include<bits/stdc++.h>

using namespace std;

map<int , int > ar ;
int arr[1001];

int solve(int a , int b){
   if(a == 0 && b == 0) return ar[0];
   if(ar[a+b] > 0){
      ar[a+b]--;
      int ans = 1+solve(b , a+b);
      ar[a+b]++;
      return ans ;
   }
   return 0;
}
int main(){
  int n  ,f1,f2,f3, x ;cin >> n ;

  for(int i=0 ; i<n ; i++){
      cin >> arr[i] ;
      ar[arr[i]]++;
  }

  int max_ = 0;
  for(int i=0 ; i<n ; i++){
      for(int j=0 ; j<n ; j++){
         if(i != j){
         ar[arr[i]]-- ; ar[arr[j]]--;
         max_ = max(max_ , solve(arr[i] , arr[j])+2);
         ar[arr[i]]++ ; ar[arr[j]]++;
        }
      }
  }
  printf("%d\n",max_);
}