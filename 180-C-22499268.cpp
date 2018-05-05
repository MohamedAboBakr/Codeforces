#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
char mssg[100005];
int n ;
int dp[100005][2] , arr[100005];

int solve(int i){
      if(i>n) return 0 ;
      if(dp[i][arr[i-1]] != -1) return dp[i][arr[i-1]] ;
      dp[i][arr[i-1]]=0;
      if(arr[i]==0){
          if(arr[i-1]==0) dp[i][arr[i-1]] = solve(i+1);
          else {
              int v1 = solve(i+1);
              arr[i] = 1;
              int v2 = 1+solve(i+1);
              dp[i][arr[i-1]] = min(v1,v2);
              arr[i] = 0 ;
          }
      }else {
           if(arr[i-1]!=0){
                dp[i][arr[i-1]] = solve(i+1);
           }
           else {
              arr[i] = 0;
              dp[i][arr[i-1]] = 1+solve(i+1);
              arr[i] = 1 ;
           }
      }
      return dp[i][arr[i-1]] ;
}

int main(){
  scanf("%s",mssg);
  n = strlen(mssg);
  int minn  ;
  arr[0] = 1 ;
  memset(dp,-1,sizeof dp);
  for(int i=0;i<n;i++){
      if(mssg[i]>='a'&&mssg[i]<='z') {
            arr[i+1] = 0;
      }
      else {
            arr[i+1] = 1 ;
      }
  }
  minn = solve(1);
  printf("%d\n",minn);
  return 0 ;
}