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
 ll n , a , b , p, q ;
 cin >> n >> a >> b ;
 cin >> p >> q ;
 ll mx = 0 ;
 ll red = n/a ;
 ll blue = n/b ;
 ll blrd = n/(a*b/__gcd(a,b));
 red -= blrd ;
 blue -= blrd ;
 mx = red*p + blue*q + max(p,q)*blrd;
 printf("%lld\n",mx);
 return 0;
}