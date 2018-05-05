#include <cstdio>
#include <vector>
#include <string>
#include <time.h>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

ll d1[10] = {0} ;
int main(){
  ll n ; cin >> n ;
  ll mistakes = 0  , correct = 0 ;
  for(int i=1 ; i<= n ; i++){
     correct += n/i ;
     ll rm = i%9 ;
     rm = (rm == 0) ? 9 : rm ;
     d1[rm]++;

  }

  for(int i=1 ; i<10 ; i++){
    for(int j=1 ; j<10 ; j++){
        int c = (i*j)%9 ; c = (c == 0) ? 9 : c ;
        mistakes += d1[c]*d1[i]*d1[j]  ;
    }
  }

  printf("%lld\n",mistakes-correct);
  return 0 ;
}