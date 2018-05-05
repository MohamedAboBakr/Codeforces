#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll ;

ll dp[105][3] ;
int n,k,d ;
ll solve(int sum , int check){
     if(sum == 0){
         if(check == 0) return 0L;
         return 1L ;
     }if(sum < 0) return 0L ;
     if(dp[sum][check] != -1) return dp[sum][check] ;
     ll ans = 0 ;
     for(int i=1; i<= min(k,sum) ; i++){
          int c=0 ;
          if(i>=d) c = 1 ;
          ans = (ans+solve(sum-i , check|c))%mod;
     }
     return dp[sum][check] = ans;
}

int main(){

  memset(dp,-1,sizeof dp);
  scanf("%d%d%d",&n,&k,&d);
  ll ans = solve(n,0);
  printf("%lld\n",ans);
  return 0 ;
}