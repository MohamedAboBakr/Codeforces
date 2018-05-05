#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
int r,g,h,mxh;
ll dp[2][200005] ;

int getblocks(int h){
    return h*(h+1)/2 ;
}

ll solve(){
     if(r>0){
            dp[1][1] = 1 ;
            if(g>0)dp[1][0]=1;
     }else{
            dp[1][0] = 1 ;
            dp[1][1] = 0 ;
      }
     for(int k=2;k<=895;k++){
          int mod = k%2 ;
          int blocks = getblocks(k);
          int flag = 0;
          for(int i=0;i<=r;i++){
                dp[mod][i]=0;
                if(blocks-i>=0 && blocks-i<=g && i>=k) dp[mod][i] = (dp[mod][i]+dp[1-mod][i-k])%(1000000007);
                if(blocks-i-k>=0 && blocks-i-k<=g ) dp[mod][i] = (dp[mod][i]+dp[1-mod][i])%(1000000007);
                if(dp[mod][i]>0) flag =1 ;
          }
          if(flag == 0){
             mxh = k-1 ;
             break ;
          }
     }

     ll ans = 0 ;
     for(int i=0;i<=r;i++){
          ans = (ans+dp[mxh%2][i])%(1000000007);
     }
     return ans ;
}

int main(){
   scanf("%d%d",&r,&g);
   h = 895 ;
   memset(dp,0,sizeof(dp));
   ll ans = solve();
   printf("%lld\n",ans);

   return 0 ;
}