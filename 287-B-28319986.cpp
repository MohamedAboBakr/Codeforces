#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main(){
  ll n,k,max_k,diff,index; scanf("%I64d%I64d",&n,&k);
  max_k = k*(k-1)/2+1;
  if(n==1){
    printf("0\n");
    return 0;
  }
  if(n>max_k){
    printf("-1\n");
    return 0;
  }
  diff = max_k-n;
  index = (-1+sqrt(1+8*diff))/2;
  printf("%I64d\n",k-1-index);
  return 0;
}