#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
int n,k ;
int dp[2][505][505];
int coin[505];
map< int , int > mp ;

int solve(){
    int ans = 0 ;
    for(int t=1; t<=n ; t++){
          int i = t%2 ;
          for(int j=0;j<=k;j++){
               for(int u=0;u<=j;u++){
                  if(j>=coin[t]&&u>=coin[t]) dp[i][j][u] = dp[1-i][j][u]|dp[1-i][j-coin[t]][u]|dp[1-i][j-coin[t]][u-coin[t]];
                  else if(j>=coin[t]) dp[i][j][u] = dp[1-i][j][u]|dp[1-i][j-coin[t]][u] ;
                  else dp[i][j][u] = dp[1-i][j][u] ;
               }
          }
    }

   for(int j=0;j<=k;j++){
              if(dp[n%2][k][j]){
                    mp[j]++ ;
              }
   }
   ans = mp.size();
   return ans ;
}

int main(){
    scanf("%d%d",&n,&k);
    memset(dp,0,sizeof(dp));
   dp[0][0][0] = 1 ;
   for(int i=1;i<=n;i++){
        scanf("%d",&coin[i]);
       // dp[i%2][0][0] = 1 ;
       // dp[i%2][coin[i]][coin[i]] = 1;
    }
    int ans = solve();
    printf("%d\n",ans);
    map< int  , int >::iterator it = mp.begin();
    printf("%d",it->first); it++;
    for( ; it != mp.end() ; it++){
         printf(" %d",it->first);
    }
    printf("\n");

   return 0 ;
}