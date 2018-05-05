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
  ll a; cin>>a;
  ll b = 1+2*(a-1);
  printf("%lld\n", b*b+2*a*(a-1));
  return 0 ;
}