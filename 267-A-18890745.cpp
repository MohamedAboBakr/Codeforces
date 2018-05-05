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
 int n , a,b;
 cin >> n ;
 while(n != 0){
    cin >> a >> b ;
    int s = 0 ,tmp ;
    int mn = min(a,b);
    int mx = max(a,b);
    while(true){
       if(mn == 1){
         s += mx;
         break ;
       }
       s +=  mx / mn ;
       tmp = mn ;
       mn = mx - (mx/mn * mn);
       mx = tmp ;
       if(mn == 0) break ;
    }
    printf("%d\n" , s);
    n--;
 }
 return 0;
}