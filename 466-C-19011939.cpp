#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int arr1[500001] = {0};
int arr2[500002] = {0};
int main(){
  int n ,l=0,r; cin >> n ;
  ll sum = 0L , pt , ans=0L ;
  for(int i=1; i<=n ; i++){
     cin>> arr1[i];
     sum += arr1[i];
  }
  if(sum%3 != 0){
    printf("0\n");
    return 0 ;
  }
  pt = sum/3 ;
  sum=0 ;
  for(int i=n; i>=0 ; i--){
     sum += arr1[i] ;
     if(sum == pt){
        arr2[i] = arr2[i+1]+1;
     }else arr2[i] = arr2[i+1];
  }

  sum=0 ;
  for(int i=1; i<= n-2 ; i++){
     sum += arr1[i] ;
     if(sum == pt){
        ans += arr2[i+2];
     }
  }
  cout << ans ;
  return 0 ;
}