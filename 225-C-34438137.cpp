#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



ll dp[2][1001];


int main(){

			int n,m,x,y;
			char pixel;	
			vector<int> blacks(1000,0);
			
            for(int i=0;i<1001;i++){
                dp[0][i]=dp[1][i]=INT_MAX;
            }
            dp[0][0]=0L;
            dp[1][0]=0L;
			scanf("%d%d%d%d",&n,&m,&x,&y); getchar();

			for(int i=0;i<n;i++){
			 for(int j=0;j<m;j++){
			    scanf("%c",&pixel);
			    if(pixel=='#') blacks[j]++; 
			 }
			 getchar();
			}
      
            for(int i=1;i<=m;i++){
                 int blk=0;
                 for(int j=i,k=0; j>=1&& k<y; j--,k++){
                      blk+= blacks[j-1];
                      if(k>=(x-1)){
                           dp[0][i] = min(dp[0][i], blk+dp[1][j-1]);
                           dp[1][i] = min(dp[1][i], (k+1)*n-blk+dp[0][j-1]);
                      }
                 }
            }
            printf("%lld\n",min(dp[0][m],dp[1][m]));
			return 0;
}