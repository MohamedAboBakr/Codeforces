#include<bits/stdc++.h>
typedef long long ll ;

char color[500005] ,result[500005];
int dp[500005][30] , prev[500005][30];
int n,k ;

void solve(){
    memset(dp,500005,sizeof(dp));
    int change = 500005 ;
    for(int i=0;i<n;i++){
          for(int j=0;j<k;j++){
                int flag = (color[i]-'A'==j)?0:1;
                for(int u=0;u<k;u++){
                      if(j!=u&&dp[i-1][u]+flag<dp[i][j]){
                           dp[i][j] = dp[i-1][u]+flag ;
                           prev[i][j] = u ;
                      }
                }
          }
    }
    int lastt ;
    for(int i=0;i<k;i++){
            if(dp[n-1][i]<change){
                change = dp[n-1][i];
                lastt = i ;
            }
    }
    printf("%d\n",change);
    int m=n ;
    while(m--){
        result[m] = (char)('A'+lastt);
        lastt = prev[m][lastt];
    }
    for(int i=0;i<n;i++){
        printf("%c",result[i]);
    }
    printf("\n");
}

int main(){
   scanf("%d%d",&n,&k);getchar();
   scanf("%s",color);
   solve();
  return 0 ;
}