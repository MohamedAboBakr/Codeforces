#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

void solve(){

}

int main(){
 ll k2,k3,k5,k6 ;
 scanf("%lld%lld%lld%lld",&k2,&k3,&k5,&k6);
 ll ans = 0 ;
 ll mn1 = min(k2 , min(k5,k6));
 ans += (mn1*256);
 k2 -= mn1 ;
 ans += (min(k2,k3)*32);
 printf("%lld\n",ans);
  return 0 ;
}