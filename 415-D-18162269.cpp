#include <iostream>

using namespace std;

long mod = 1e9 + 7 ;
int main()
{

    int N , k;
    cin >> N >> k;
    long dp[N][k] , ans = 0;

    for (int i = 0; i < N; i++)
        dp[i][0] = 1 ;

    for (int j = 1; j < k ; j++)
      for (int i = 0; i < N; i++)
    {
       long sum = 0 ;
       for(int div = i ; div < N ; div += i+1){
          sum = ( sum%mod  + dp[div][j-1]%mod)%  mod ;
       }
       dp[i][j] = sum ;
    }

    for(int i=0 ; i<N ; i++){
        ans = (ans%mod + dp[i][k-1]%mod)% mod ;
    }
    cout << ans;
    return 0;
}