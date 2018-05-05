#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main(){
  ll t,n ;
  scanf("%lld",&t);
  while(t--){
      scanf("%lld",&n);
      if(n%2==0) printf("%lld\n",4*n+1);
      else{
        if((n-1)%4 == 0) printf("%lld\n",2*n+1);
        else printf("%lld\n",n+1);
      }
  }
  return 0 ;
}