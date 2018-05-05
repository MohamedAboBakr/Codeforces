#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define MAX 1e18

void solve_equ(ll c1 , ll c2  , ll *x , ll *y){
    *x = (c1+c2)/2 ;
    *y = *x-c1 ;
}
int main(){
  ll n,x,y; scanf("%lld",&n);
  if(n<3){
     printf("-1\n"); return 0 ;
  }
  ll n_p2 = n*n ;
  if(n_p2&1) solve_equ(1,n_p2,&x,&y);
  else solve_equ(2,n_p2/2,&x,&y);

  printf("%lld %lld\n",x,y);
  return 0 ;
}