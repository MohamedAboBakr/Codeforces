#include <bits/stdc++.h>
using namespace std;
int arr[100002]  = {0} ;
int main(){
  int n ; scanf("%d",&n);
  int x ;
  int mxx = 0 ;
  for(int i=0; i<n ; i++){
      scanf("%d",&x);
      arr[x] = arr[x-1]+1;
      mxx = max(mxx , arr[x]);
    }
   printf("%d\n",n-mxx);
  return  0;
}