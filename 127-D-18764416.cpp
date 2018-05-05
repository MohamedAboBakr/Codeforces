#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <string>
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int arr[1000001] ;
void preKmp(string x, int m ) {
   int i, j;
   i = 0;
   j = -1;
  arr[0] = -1;
   while (i < m) {
      while (j > -1 && x[i] != x[j])
         j = arr[j];
      i++;
      j++;
      arr[i] = j;

   }
}


int KMP(string x, int m, string y, int n , int k) {
   int i, j , ans =  0;
   i = j = 0;
   while (j < n) {
      while (i > -1 && x[i] != y[j])
         i = arr[i];
      i++;
      j++;
      if (i == k) {
         ans++ ;
         i = arr[i];
      }
   }
  // printf("%d\n" , arr[n]);
   return (ans>2) ;
}

string solve(string txt){
  int n = txt.length();
  string ans ;
  if(n < 3){
    ans = "Just a legend";
    return ans ;
  }
  preKmp(txt , n);
  int last = arr[n] ;
  if(last == 0){
    ans = "Just a legend";
    return ans ;
  }

  if(KMP(txt,n,txt,n,last)){
      ans = txt.substr(0,last);
  }
  else if(arr[last] > 0){
      ans = txt.substr(0,arr[last]);
  }
  else{
    ans = "Just a legend";
  }
  return ans ;
}

int main(){
  string txt ;
  cin >> txt ;
  cout << solve(txt);
  return 0 ;
}