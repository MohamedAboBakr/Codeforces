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
    int a , ta ; scanf("%d%d",&a,&ta);
    int b , tb ; scanf("%d%d",&b,&tb);
    int h , m , t ;
    scanf("%d:%d",&h,&m);
    m += h*60;
    t = m+ta ;
   // printf("%d %d\n" , m , t);
    int i= 5*60 ;
    int ans = 0 ;
    while( i < 24*60){
         if(max(i , m) < min(i+tb , t)){
                ans ++ ;
         }
         i+=b;
    }
    printf("%d\n" , ans);
  return 0;
}