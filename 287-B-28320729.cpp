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

  ll l=1 , r=k-1,mid;
  while(l<r){
     mid = (l+r)/2;
     ll mn,mx;
     index = k-1-mid;
     mx = max_k-index*(index+1)/2;
     mn = mx-index;
     if(n>=mn&&n<=mx){
            l = mid;
            break;
     }
     if(n<mn)r=mid-1;
     else l=mid+1;
  }
  printf("%I64d\n",l);
  return 0;
}