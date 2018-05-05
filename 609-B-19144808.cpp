#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int type[11] = {0};
int sum[11] = {0};
int main(){
  int n , m ,x; cin >> n >> m ;
  for(int i=0;i<n;i++){
    cin >> x ; type[x]++;
  }
  for(int i=1 ; i<11 ; i++){
    sum[i] = type[i]+sum[i-1];
  }
  ll ans = 0 ;
  for(int i=1 ; i<11 ; i++){
    ans += type[i]*sum[i-1];
  }
  cout << ans ;
  return 0;
}