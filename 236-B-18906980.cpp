#include <cstdio>
#include <vector>
#include <string>
#include <time.h>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define mod 1073741824


int dv[1000001] = {0} ;

void get_c(ll n){

 dv[n] = 2 ;
 ll sqt = sqrt(n);
 for(ll i = 2 ; i<= sqt ; i++){
    if(n%i == 0) {
        if(n/i == i) dv[n] ++ ;
        else dv[n] += 2 ;
    }
 }
 // printf("%lld %lld\n" , n , dv[n]);
}
int main()
{
 dv[1] = 1 ;
 ll a,b,c ; cin >> a >> b >> c ;
 ll ans = 0 ;
 for(int i=1 ; i<= a ; i++){
    for(int j = 1 ; j<= b ; j++){
        for(int k = 1 ; k<= c ; k++){
            if(dv[i*j*k] != 0) ans = (ans+dv[i*j*k])%mod ;
            else{
                get_c(i*j*k);
                ans = (ans+dv[i*j*k])%mod ;
            }
        }
    }
 }
 printf("%lld\n",ans%mod);
 return 0;
}