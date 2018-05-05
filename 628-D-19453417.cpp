#include <cstdio>
#include <vector>
#include <string.h>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int mod = 1e9+7 ;
ll dp[2001][2001] ;
int m,d,n ;
char a[2001] , b[2001];
void set_(){
       memset(dp , -1 , sizeof(dp));
}

int solve(char* str , int rem , int index  , int flag){
       if(index == n) return rem == 0;
       if(!flag && dp[index][rem] != -1) return dp[index][rem];
       int end_ = (flag == 1)? str[index]-'0' : 9 ;
       int res = 0L ;
       for(int i=0 ; i<= end_ ; i++){
            if(index%2==1 && i!= d) continue ;
            if(index%2==0 && i==d) continue ;
            res = (res + solve(str , (rem*10 + i)%m , index+1 , flag && (i == end_)))%mod ;
       }

       if(flag==0) dp[index][rem] = res;
       return res ;
}

void subtract_one(int len){

   for(int i=len-1; i>= 0 ; i--){
      if(a[i] == '0') a[i] = '9';
      else{
        a[i] -- ;
        break ;
      }
   }
}
int main(){

  scanf("%d%d",&m,&d);
  scanf("%s%s",a,b);
  n = strlen(a);
  subtract_one(n);
  set_();
  int b_ = solve(b , 0 , 0 ,1);
  set_();
  int a_ = solve(a , 0 , 0 ,1);
  printf("%d\n" , (b_ - a_+ mod)%mod);
  return 0 ;
}