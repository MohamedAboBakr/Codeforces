#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int dp[31][31][51];
int main(){

  for(int i=1; i<=30 ;i++){
      for(int j=1 ; j<=30 ; j++){
         int v = i*j ;
         int mn = min(i*j , 50);
         dp[i][j][0] = 0 ;
         for(int k=1 ; k <= 50 ; k++){
             if(k == v) dp[i][j][k] = 0 ;
             else{
                dp[i][j][k] = 1000000 ;
                for(int t=0 ; t<=k ; t++){
                    for(int h = 1 ; h< i ; h++){
                        dp[i][j][k] = min(dp[i][j][k] , j*j + dp[h][j][t]+ dp[i-h][j][k-t]);
                    }
                    for(int h = 1 ; h< j ; h++){
                        dp[i][j][k] = min(dp[i][j][k] , i*i + dp[i][h][t]+ dp[i][j-h][k-t]);
                    }
                }

             }
         }              
      }
  }
 int t ,n,m,k; cin >> t ;
 while(t>0){
    cin >> n>> m >> k;
    printf("%d\n",dp[n][m][k]);
    t-- ;
 }

 return 0 ;
}