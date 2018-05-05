#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;


int main(){
    ll n  ; scanf("%lld",&n);
    ll f1=1,f2=2,f3=0,ans=0;
    while(f3<=n){
         f3 = f1+f2 ;
         f1 = f2 ;
         f2 = f3 ;
         ans ++ ;
    }
    printf("%d\n",ans);
   return 0 ;
}