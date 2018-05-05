#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;


int main(){
  int n,m ;
  scanf("%d%d",&n,&m);
  int mn,mx ;
  mn= min(n,m);
  mx= max(n,m);

  ll ans = 0 ;
  for(int i=1 ;  i<=mn ; i++){
      int first = (int)ceil(1.0*i/5)*5 - i;
      if(first == 0) first = 5 ;
      ans += (ll)ceil(1.0*(mx+1-first) / 5) ;
  }
  printf("%lld\n",ans);
  return 0;
}