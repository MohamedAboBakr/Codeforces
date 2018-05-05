#include<bits/stdc++.h>
    using namespace std;
    typedef long long ll ;

    int main(){
      int n ;
      scanf("%d",&n);
      if(n==1){
         printf("-1\n");
         return 0 ;
      }
      printf("%d %d %d\n",n,n+1,n*n+n);
      return 0 ;
    }