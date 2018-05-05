#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

bool prime(ll n){
    if(n == 2) return true ;
    ll sqrtt = (ll)sqrt(n);
    for(int i=2 ; i<= sqrtt ; i++){
          if(n%i == 0) return false ;
    }
    return true ;
}
int main(){
   ll n ; scanf("%lld",&n);
   if(prime(n)){
      printf("1\n");
      return 0 ;
   }
   if(n%2==0){
      printf("2\n");
      return 0 ;
   }
   if(prime(n-2)){
      printf("2\n");
   }else printf("3\n");
   return 0 ;
}