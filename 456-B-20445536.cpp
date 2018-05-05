#include<bits/stdc++.h>
using namespace std;
typedef long long  ll ;

ll mod = 5 ;
ll _2 , _3 ;
ll __2 = 1 , __3 = 1 ;

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

void solve(string s){
     int len = s.length();
     ll val = 0 ;
     ll p = 0 ;
     ll p_2 = 2 , p_3 =3 ;
    // int j=0 ;
     for(int i=len-1 ; i>=0 ; i--){
          if(p==0){
                val = s[i]-'0' ;
                p = 10 ;
          }
          else{
                val += (p*(s[i]-'0'));
                p *= 10 ;
          }
          if(p == 10000){
             __2 = (__2 * Power(p_2 , val))%mod ;
             __3 = (__3 * Power(p_3 , val))%mod ;
             if(p_2 == 2) p_2 = _2 ;
             if(p_3 == 3) p_3 = _3 ;
             val = 0 ;
             p = 0 ;
          }
     }

     if(val != 0) {
             __2 = (__2 * Power(p_2 , val))%mod ;
             __3 = (__3 * Power(p_3 , val))%mod ;
     }
}
int main(){
   _2 = Power(2,100000);
   _3 = Power(3,100000);
  string s ;
  cin >> s ;
  ll ans  ;
  solve(s);
  ans = (1+__2+__3+(__2*__2))%5;
  printf("%lld\n",ans);
  return 0 ;
}