#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main(){

  int n ; cin >> n ;
  int sum_1 = 0 , sum_0 = 0 , last_1 , max_ = 0;
  int arr[n];
  for(int i=0 ; i<n ; i++){
    cin >> arr[i] ;
  }
  getchar(); char c[n] ;
  for(int i=0 ; i<n ; i++){
        c[i] = getchar();
        if(c[i] == '1'){
            sum_1 += arr[i];
        }
        else sum_0 += arr[i];
    }
  max_ = sum_1 ;
  for(int i=n-1 ; i >= 1 ; i-- ){
        if(c[i] == '0') sum_0 -= arr[i] ;
        else{
            max_ = max(max_ , sum_1-arr[i]+sum_0);
        }
    }


   printf("%d\n" , max_);
}