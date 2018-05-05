#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[501][501]={0};
int ci[500];
int main(){
  int n; scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%d",&ci[i]);

  for(int i=0;i<n;i++) dp[i][i]=1;
  for(int i=0;i<n-1;i++){
      if(ci[i]==ci[i+1]) dp[i][i+1]=1;
      else dp[i][i+1]=2;
  }

  for(int k=3;k<=n;k++){
  	 for(int i=0;i<n-k+1;i++){
  	 	  int mn = 1+dp[i+1][i+k-1];
  	 	  if(ci[i]==ci[i+1]) mn=min(mn,1+dp[i+2][i+k-1]);
  	 	  int mn2=600;
  	 	  for(int j=i+2;j<=i+k-1;j++){
  	 	  	if(ci[j]==ci[i]) mn2 = min(mn2,dp[i+1][j-1]+dp[j+1][i+k-1]);
  	 	  }
  	 	  mn = min(mn,mn2);
  	 	  dp[i][i+k-1]=mn;
  	 }
  }
  printf("%d\n",dp[0][n-1]);
	return 0;
}