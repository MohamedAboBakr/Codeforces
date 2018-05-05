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
  ll n ; cin >> n ;
  ll x = ((ll)sqrt(8*n+1)-1)/2;
  ll rem = n%(x*(x+1)/2);
  printf("%lld\n" , (rem == 0) ? x : rem );
 return 0 ;
}