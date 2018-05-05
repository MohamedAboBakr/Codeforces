#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll pow2[60];

int solve(int n , ll k){
     if(k == pow2[n-1]) return n ;
     if(k < pow2[n-1])  return solve(n-1 , k);
     return solve(n-1 , k-pow2[n-1]);
}
int main(){
   pow2[0] = 1 ;
   for(int i = 1 ; i<= 50 ; i++){
      pow2[i] = 2*pow2[i-1];
   }
   int n;ll k ; scanf("%d%lld",&n,&k);
   printf("%d\n",solve(n,k));
  return 0 ;
}