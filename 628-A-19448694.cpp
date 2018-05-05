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
  int n,b,p ,ans=0;
  int matches = 0 ;
  cin >>n>>b>>p ;
  ans += p*n ;
  while(n!=1){
    matches += n/2 ;
    n -= n/2 ;
  }
  printf("%d %d\n" , matches*(2*b+1) , ans);
  return 0 ;
}