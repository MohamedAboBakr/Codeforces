#include <cstdio>
#include <vector>
#include <string>
#include <time.h>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;


ll get_c(ll n){
 ll sqt = sqrt(n);
 for(ll i = 2 ; i<= sqt ; i++){
    if(n%i == 0) return n/i ;
 }
 return 0L ;
}
int main()
{

 ll n ; cin >> n ;
 ll mx = n ;
 while(true){
    n = get_c(n);
    if(n == 0){
        mx ++ ;
        break;
    }
    mx += n ;
 }
 printf("%lld\n",mx);
 return 0;
}