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
  ll a = 1;
  string s ; cin >> s ;
  int c = 0 , f = s[0] - '0' , len = s.length() , i=1 ,lst;
  while(i<len){
    lst = s[i]-'0' ;
    if(lst + f == 9){
        c++ ;
    }else{

        if(c>0 && c%2 == 0){
            a *= (c/2+1) ;
            c=0 ;
        }
        c=0 ;
    }

    f = lst ;
    i++;
  }
    if(c>0 && c%2 == 0){
            a *= (c/2+1) ;
            c=0 ;
        }
  cout << a ;
  return 0 ;
}