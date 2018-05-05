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
 ll n ;
 cin >> n ;
 if(n<3){
    printf("%lld\n",n);
    return 0;
 }
 if(n %2 == 1){
    printf("%lld",n*(n-1)*(n-2));
    return 0 ;
 }

 ll v = (n-1)*(n-2)*(n-3) ;
 ll v2 = n*(n-1)*(n-3)/__gcd(n , n-3);
 printf("%lld\n",max(v , v2));
 return 0;
}