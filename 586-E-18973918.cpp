#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

ll mx = LLONG_MAX ;
int main(){
  ll a , b ;
  cin >> a >> b ;
  ll gcd = __gcd(a,b);
  if(gcd != 1){
    printf("Impossible\n");
    return 0 ;
  }

  while(a > 0 && b > 0){
     if(a > b) {
        cout << (a-1)/b << "A" ;
        a %= b ;
     }else{
        cout << (b-1)/a << "B" ;
        b %= a ;
     }
  }
  return 0 ;
}