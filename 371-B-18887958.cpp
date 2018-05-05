#include <cstdio>
#include <vector>
#include <string>
#include <time.h>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main()
{
 int a , b ;
 cin >> a >> b;
 if(a == b) {
    printf("0\n");
    return 0 ;
 }
 int gcd = __gcd(a,b);
 a /= gcd ;
 b /= gcd ;

 int mn = 0 ;
 while( a!= 1){
    if(a % 2 == 0) {
        mn ++ ;
        a /= 2 ;
        if(a == 0) break ;
    }
    else if( a%3 == 0){
        mn ++ ;
        a /= 3 ;
        if(a == 0) break ;
    }
    else if( a%5 == 0){
        mn ++ ;
        a /= 5 ;
        if(a == 0) break ;
    }
    else{
        printf("-1\n");
        return 0 ;
    }
 }

  while( b != 1){
    if(b % 2 == 0) {
        mn ++ ;
        b /= 2 ;
        if(b == 0) break ;
    }
    else if( b%3 == 0){
        mn ++ ;
        b /= 3 ;
        if(b == 0) break ;
    }
    else if( b%5 == 0){
        mn ++ ;
        b /= 5 ;
        if(b == 0) break ;
    }
    else{
        printf("-1\n");
        return 0 ;
    }
 }

 printf("%d\n",mn);
 return 0;
}