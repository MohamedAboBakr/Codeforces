#include<bits/stdc++.h>
    using namespace std;
    typedef long long ll ;

    int main(){

          int n ; scanf("%d",&n);
          int srt = (int)sqrt(n);
          int a , b , minn = 1000005 ;
          for(int i=1 ; i<=srt ; i++){
              if(n%i==0){
                  int x = i , y = n/i ;
                  if(abs(x-y)<minn){
                     minn = abs(x-y);
                     a = min(x,y);
                     b = max(x,y);
                  }
              }

          }
          printf("%d %d\n",a,b);
          return 0 ;
      }