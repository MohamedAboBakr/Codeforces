#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <stdio.h>
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef  long long   ll;
map<ll, ll> arr ;
ll ans = 1 ;
ll  Power(ll base , ll times){
        if(base == 0) return 0L;
        if(times == 1) return base ;
        ll ans = 1 ;
        ll  base_binary = base ;
        while(times > 0){
            if(times % 2 == 1) ans = ((ans%mod) * (base_binary%mod))%mod ;
            base_binary = (base_binary % mod)*(base_binary % mod)%mod;
            times /= 2 ;
        }
        return ans%mod ;
}

int main(){
   int n; cin>> n ;
   vector<ll> powers ;
   ll x ;
   for(int i=0 ; i<n ; i++){
      scanf("%lld",&x);
      arr[x]++;
   }

   ll pp = 1L ;
   int flag = 0;
  map <ll, ll >::iterator it;
  for (it = arr.begin(); it != arr.end(); ++it){
      ll s = it->second + 1 ;
      if(flag == 0 && s%2 ==0){
            s /= 2 ;
            flag = 1 ;
      }

      pp *= s ;
      if(pp > 2000000000000) {
        powers.push_back(pp);
        pp = 1L;
      }
  }

  powers.push_back(pp);
  if(flag == 0){
    for (it = arr.begin(); it != arr.end(); ++it){
      ll p = Power(it->first , it->second /2);
      ans = ((ans%mod)*(p%mod))%mod;
    }
  }

  else{
    for (it = arr.begin(); it != arr.end(); ++it){
      ll p = Power(it->first , it->second );  ;
      ans = ((ans%mod)*(p%mod))%mod;
    }
  }

  int sz = powers.size();
  for(int i=0; i<sz ; i++){
    ans = Power( ans , powers[i]);
  }
  printf("%lld\n",ans%mod);
  }