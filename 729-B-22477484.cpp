#include<bits/stdc++.h>
//using namespace std;
typedef long long ll ;

int down[1002][1002],up[1002][1002];
int left[1002][1002],right[1002][1002];
int grid[1001][1001];
int n,m ;

ll  solve(){
      for(int i=1; i<=m ; i++){
           up[n+1][i] = n+1;
           for(int j=1;j<=n ; j++){
               if(grid[j][i] == 1) down[j][i] = j ;
               else down[j][i] = down[j-1][i] ;
           }
           for(int j=n;j>=1 ; j--){
               if(grid[j][i] == 1) up[j][i] = j ;
               else up[j][i] = up[j+1][i] ;
           }
      }
      for(int i=1; i<=n ; i++){
           left[i][m+1] = m+1 ;
           for(int j=1;j<=m ; j++){
               if(grid[i][j] == 1) right[i][j] = j ;
               else right[i][j] = right[i][j-1] ;
           }
           for(int j=m;j>=1 ; j--){
               if(grid[i][j] == 1) left[i][j] = j ;
               else left[i][j] = left[i][j+1];
           }
      }

      ll ans = 0  ;
      for(int i=1 ; i<=n ; i++){
          for(int j=1 ; j<=m ; j++){
              if(grid[i][j]==1){
                  ans += (down[i][j]-down[i-1][j]-1)+(up[i+1][j]-up[i][j]-1)+(right[i][j]-right[i][j-1]-1)+(left[i][j+1]-left[i][j]-1);
              }
          }
      }
      return ans ;
}


int main(){
    scanf("%d%d",&n,&m);
    memset(down,0,sizeof(down));
    memset(down,0,sizeof(up));
    memset(down,0,sizeof(left));
    memset(down,0,sizeof(right));
    for(int i=1;i<=n ; i++){
         for(int j=1;j<=m;j++){
            scanf("%d",&grid[i][j]);
         }
    }
  ll ans = solve();
  printf("%lld\n",ans);
  return 0 ;

}