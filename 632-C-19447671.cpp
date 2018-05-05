#include <cstdio>
#include <vector>
#include <string.h>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;


bool small(string a , string b){
   return  (a+b)<(b+a) ;
}

int main(){
  int n ; scanf("%d\n" , &n);
  string arr[n] ;
  for(int i=0 ; i<n ;i++){
    string st ; cin >> st ;
    arr[i] = st;
  }
  sort(arr , arr+n , small);
  for(int i=0;i<n ; i++){
     cout << arr[i] ;
  }
  cout << "\n";
  return 0 ;
}