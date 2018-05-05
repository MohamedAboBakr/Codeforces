#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

map <ll , int > visit ;
int main(){
  ll a,b,r0,m ; scanf("%lld%lld%lld%lld",&a,&b,&m,&r0);
  ll r = r0 ;
  int t = 1 ;
  while(true){
      r = ((a*r)%m+b)%m ;
     // printf("%lld\n",r);
      if(visit.find(r) != visit.end()){
          printf("%d\n",t-visit[r]);
          return 0 ;
      }
      visit[r] = t++;
  }
  return 0 ;
}