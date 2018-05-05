#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main(){
   ll d,k,a,b,t,ans;
   scanf("%lld%lld%lld%lld%lld",&d,&k,&a,&b,&t);
   if(d<=k){
      printf("%lld\n",a*d);
      return 0;
   }
   ll t1 = k*a+t ;
   ll tt1 = k*b ;
   int num = d/k ;
   if(tt1<t1){
      ans = a*k + (d-k)*b;
      printf("%lld\n",ans);
      return 0 ;
   }

   d -= k ;

   ans = a*k + (d/k)*t1;
   ans += min((d%k)*a+t , (d%k)*b);
   printf("%lld\n",ans);
   return 0;
 }