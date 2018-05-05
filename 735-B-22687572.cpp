#include<bits/stdc++.h>
using namespace std;
typedef  double ld ;

int main(){
   int n,n1,n2 ;
   scanf("%d%d%d",&n,&n1,&n2);
   int wealth[n];
   for(int i=0;i<n;i++){
      scanf("%d",&wealth[i]);
   }
   sort(wealth , wealth+n);
   ld sum = 0.0  , mxsum = 0.0;
   for(int i=0;i< n1+n2 ; i++){
      sum += 1.0*wealth[n-i-1];
      if(i<min(n1,n2)) mxsum = sum ;
   }

  ld ans = mxsum/(1.0*min(n1,n2)) + (sum-mxsum)/(1.0*max(n1,n2));
  // cout << sum << "  " << mxsum << "\n" << ans;
  printf("%.8lf\n",ans);

   return 0 ;
}