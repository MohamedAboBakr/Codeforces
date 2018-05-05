#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef  long long  ll ;


int main(){
   int n ; scanf("%d",&n);
   int sm1 = 0 , sm2 =  0 ;
   string s; cin >> s ;
   for(int i=0 ; i<n ; i++){
       if(s[i] != '4' && s[i] != '7') {
           printf("NO\n");
           return 0 ;
       }
       if(i < n/2) sm1 += (s[i]-'0');
       else sm2 += (s[i]-'0');
   }
   printf("%s\n",(sm1 == sm2)?"YES":"NO");
  return 0 ;
}