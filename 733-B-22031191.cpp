#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int arr[100005][2];
int R,L ;
int mxxdif ,ans=0;
int main(){
  int n;scanf("%d",&n);
  for(int i=0;i<n;i++){
     scanf("%d%d",&arr[i][0],&arr[i][1]);
     L += arr[i][0];
     R += arr[i][1];
  }

  mxxdif = abs(L-R);

  for(int i=0;i<n;i++){
     L = L-arr[i][0]+arr[i][1];
     R = R-arr[i][1]+arr[i][0];
     if(abs(L-R) > mxxdif){
      mxxdif = abs(L-R) ;
      ans = i+1 ;
     }
     L = L-arr[i][1]+arr[i][0];
     R = R-arr[i][0]+arr[i][1];
  }

  printf("%d\n",ans);
  return 0 ;
}