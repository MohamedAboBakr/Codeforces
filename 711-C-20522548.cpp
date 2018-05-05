#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll mxx = 1e12 ;
int n,m,k,ini_k=0;
int c[105] ;
ll p[105][105];
ll dp[105][105][105];



ll solve(int index , int curr_k , int lst_col){
     if(index == n) {
           if(curr_k == k) return 0L;
           return mxx ;
     }


     if(dp[index][curr_k][lst_col] != -1){
           // printf("%d %d\n",index,curr_k);
            return dp[index][curr_k][lst_col] ;
     }
     ll mn1 = mxx ;
     if(c[index] == 0){


                for(int i=1 ; i<=m ; i++){
                     if(i == lst_col)  mn1 = min(mn1 , p[index][i]+solve(index+1 , curr_k , i)) ;
                     else mn1 = min(mn1 , p[index][i] + solve(index+1 , curr_k+1 , i));

                }

        }

        else{

              if(c[index] == lst_col) mn1 = min(mn1 ,  solve(index+1 , curr_k , lst_col)) ;
              else mn1 = min(mn1 ,  solve(index+1 , curr_k+1 , c[index] ));

      }

    return  dp[index][curr_k][lst_col] = mn1 ;

    }


int main()
{
    memset(dp , -1 , sizeof(dp)) ;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0 ; i<n ; i++) {
            scanf("%d",&c[i]);
    }

    for(int i=0;i<n;i++)for(int j=1;j<=m;j++) scanf("%lld",&p[i][j]);

    ll mn = solve(0,0,0);
    printf("%lld\n",(mn==mxx)? -1 : mn);
    return 0;
}