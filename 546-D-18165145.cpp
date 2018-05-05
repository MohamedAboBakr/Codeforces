#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

#define N 5000000
int dp[N] ;
int main(void) {
    
    int i = 2;
	while(i<N){
		if(dp[i]==0)
			for(int j=i;j<=N;j+=i)
				dp[j]=dp[j/i]+1;
		i++ ;
	}
    i=1 ;
	while(i<=N){
		dp[i]+=dp[i-1];
		i++ ;
	}
    int t;
	scanf("%d",&t);
	while(t--)
	{
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d \n",(dp[a]-dp[b]));
	}
	return 0;
}