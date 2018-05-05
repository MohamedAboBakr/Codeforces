#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int Xor[1000005]={0};
int currXor=0;

int main(){
   ll n , ans=0 , sum ,p;
   Xor[1] = 1 ;
   scanf("%lld",&n);
   for(int i=1 ; i<=n ; i++){
       scanf("%lld",&p);
       Xor[i] = Xor[i-1]^i ;
       currXor ^= (i-1) ;
       if((n/i)%2 == 1) ans ^= currXor ;
       ans ^= Xor[n%i];
       ans ^= p ;
   }
   printf("%lld\n",ans);
   return 0;
}