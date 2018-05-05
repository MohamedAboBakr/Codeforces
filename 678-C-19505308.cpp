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
   ll n , a,b,p,g ;
   scanf("%lld%lld%lld%lld%lld" , &n,&a,&b,&p,&g);
   ll lcm = (a*b)/__gcd(a,b);
   ll s = 0 ;
   s += (n/lcm)*max(p,g);
   s += (n/a- n/lcm)*p ;
   s += (n/b- n/lcm)*g ;
   printf("%lld\n" , s);
   return 0 ;
}