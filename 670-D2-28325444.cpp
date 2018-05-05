#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

vector<ll>a,b;

int main(){
  ll n,k,x,s=0; scanf("%lld%lld",&n,&k);
  for(int i=0;i<n;i++){
      scanf("%lld",&x);
      a.push_back(x);
  }
  for(int i=0;i<n;i++){
      scanf("%lld",&x);
      b.push_back(x);
  }

  ll l=0,r=2e9;
  ll z=0L,mx;
  while(r-l >1){
      ll mid = (l+r)/2;
      ll ans=0;
      for(int i=0;i<n;i++){
         ans += max(z,mid*a[i]-b[i]);
         if(abs(ans)>k) break;
      }
     // printf("%lld\n",ans);
      if(ans<=k){
        mx=l;
        l = mid;
      }
      else r=mid-1;
      if(l==r){
        mx=l;
        break;
      }
  }
  if(l==r) printf("%lld\n",mx);
  else {
      ll ans=0;
      for(int i=0;i<n;i++){
         ans += max(z,r*a[i]-b[i]);
      }
      if(ans<=k)printf("%lld\n",r);
      else printf("%lld\n",l);
  }
  return 0 ;
}