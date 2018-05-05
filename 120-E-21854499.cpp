#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main(){
   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
  int t,n;scanf("%d",&t);
  while(t--){
      scanf("%d",&n);
      int ans = n*(n/2)+((n&1)?(int)ceil(1.0*n/2):0);
      printf("%d\n",(ans&1)?0:1);
  }
  return 0;
}