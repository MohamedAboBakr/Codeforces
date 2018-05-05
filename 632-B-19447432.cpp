#include <cstdio>
#include <vector>
#include <string.h>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main(){
    int n ; cin >> n ;
    int str[n] ;
    for(int i=0; i<n ; i++){
        cin >> str[i];
    }
    getchar();
    ll a=0 , b=0 ;
    char c[n] ;
    for(int i=0 ; i<n ; i++){
        c[i] = getchar();
        if(c[i] == 'A') a+=str[i] ;
        else b += str[i];
    } getchar();


    ll ans1 = 0 , ans2 = 0 ;
    ll m1 = b , m2 = b ;
    for(int i=0 ; i<n ; i++){
        if(c[i] == 'A'){
            m1 += str[i] ;
            ans1 = max(ans1 , m1);
        }else{
            m1 -= str[i];
        }
    }
     ans1 = max(ans1 , m1);
  //  printf("%lld\n" , ans1);
    for(int i=n-1 ; i>=0 ; i--){
         if(c[i] == 'A'){
            m2 += str[i] ;
            ans2 = max(ans2 , m2);
        }else{
            m2 -= str[i];
        }
    }
    ans2 = max(ans2 , m2);
    b = max(b  ,max(ans1 , ans2)); cout << b ;
   return 0 ;
}