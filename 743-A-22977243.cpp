#include<bits/stdc++.h>
    using namespace std;
    typedef long long ll ;

    int main(){
      int n,a,b ;
      scanf("%d%d%d",&n,&a,&b);
      string s ; cin >>s ;
      if(s[a-1]==s[b-1]){
          printf("0\n");
          return 0 ;
      }

      printf("1\n");
      return 0 ;
    }