#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

ll get_comp(int l , int stick , int sum){
  ll c = 0 , s , rest , mn;
  for(int i=0 ; i<= l ; i++){
     s = stick+i ;
     if(s < sum) continue ;
     rest = l-i ;
     mn = min(rest , s-sum) ;
     c += (mn+1)*(mn+2)/2 ;
  }
  return c ;
}
int main(){
  ll a , b , c , l;
  ll all_ways = 0;
  ll complement = 0;
  cin >> a >> b >> c >> l;
  all_ways = (l+1)*(l+2)*(l+3) / 6 ;
  complement += get_comp(l , a , b+c);
  complement += get_comp(l , b , a+c);
  complement += get_comp(l , c , b+a);
  printf("%lld\n",all_ways - complement );
  return 0 ;
}