#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define N 2000
using namespace std;

long double dp[N][N] = {0};

long double nChoosek( double n, double k )
{
    if(n == 0) return 1L ;
    if (k > n) return 0L;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1L;

    long double result = n;
    for( long i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}


long double get_comb(int a , int b){
   if(dp[a][b] != 0) return dp[a][b] ;
   if(a != 0){
      if(dp[a-1][b] != 0 && dp[a-1][b-1] != 0){
        dp[a][b] = dp[a][a-b] = dp[a-1][b] + dp[a-1][b-1] ;
        return dp[a][b] ;
      }
   }
   dp[a][b] = dp[a][a-b] = nChoosek(a,b);
   return dp[a][b] ;

}


int main(void) {

    double p , P , Q ;
    int n , t ;
    cin >> n >> p >> t;
    if(p == 0.0){
        printf("%0.6f\n",0);
        return 0 ;
    }
    P = p ;
    Q = 1.0 - P ;
    long double res = 0.0 ;
    for(int i=1 ; i<=t && i<=n ; i++ ){

        int End = i , enter = i-1 ;
        long double ans = 0.0 ;
        while(End <= t ){

            ans += (get_comb(End -1 , enter))*powl(Q , (double)(End-1-enter));
            End ++ ;
        }
        res += (ans * powl(P , (double)i));

    }
    double d = res ;
    printf("%0.9f\n",d);
	return 0;
}