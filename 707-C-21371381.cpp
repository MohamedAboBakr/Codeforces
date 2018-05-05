#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll ;
#define MAX 1e18

void try1(ll n , ll *y , ll *z){
   ll x = n*n ;
   ll index = (x+1)/2 ;
   *y = (index-1);
   *z =  index ;
}


int main(){
  ll n ,y,z; scanf("%lld",&n);
  if(n<3){
     printf("-1\n"); return 0 ;
  }
  if(n%5==0){
      printf("%lld %lld\n",(n/5)*4 , (n/5)*3); return 0 ;
  } if(n%4==0){
      printf("%lld %lld\n",(n/4)*3 , (n/4)*5); return 0 ;
  }if(n%3==0){
      printf("%lld %lld\n",(n/3)*4 , (n/3)*5); return 0 ;
  }

  ll srt = (ll) sqrt(n);
  for(int i=1 ; i<= srt ; i++ ){
      if(n%i == 0){
           if(i&1 && i!=1){
                try1(i,&y,&z);
                printf("%lld %lld\n",y*(n/i),z*(n/i));
                return 0 ;
           }
           if((n/i)&1){
                try1(n/i,&y,&z);
                printf("%lld %lld\n",y*(i),z*(i));
                return 0 ;
           }
      }
  }
  printf("-1\n");
  return 0 ;
}