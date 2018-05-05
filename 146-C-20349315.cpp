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
   string a , b ;
   cin >> a >> b ;
   int count_4 = 0 , count_7 = 0 ;
   for(int i=0; i< a.length() ; i++){
      if(a[i] == b[i]) continue ;
      if(a[i] == '4') count_4++ ;
      else count_7++ ;
   }
   printf("%d\n",max(count_7 , count_4));
  return 0 ;
}