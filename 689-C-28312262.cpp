#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

ll ways(ll n){
   ll k = 2,i;
   ll ans = 0 ;
   while(true){
      i=k*k*k;
      if(i>n) break;
      ans += n/i;
      k++;
   }
   return ans ;
}

int main(){
 ll m,ans;
 scanf("%lld",&m);
 ll l=0,r=1e16;
 while(l<r){
     ll mid = (l+r)/2;
     ans = ways(mid);
     if(ans>=m) r=mid;
     else l=mid+1;
 }
 if(ways(l)==m) ans=l;
 else ans = -1;
 printf("%lld\n",ans);
 return 0 ;
}