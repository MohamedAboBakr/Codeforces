#include<bits/stdc++.h>
    using namespace std;
    typedef long long ll ;

    int main(){
          int n ,q; scanf("%d%d",&n,&q);
          ll servers[n+1] ; memset(servers,0,sizeof servers);

          ll t,k,d ;
          for(int i=0 ; i<q ; i++){
              scanf("%lld%lld%lld",&t,&k,&d);
              ll t2 = t+d ;
              ll s = 0 , k2=0;

              for(int j=1 ; j<=n ; j++){
                  if(servers[j]<=t){
                      k2++;
                      s += j;
                      if(k2>=k) break ;
                  }
              }

              if(k2 < k){
                 printf("-1\n");
              }else{

                   for(int j=1 , v=0; v<k ; j++){
                          if(servers[j]<=t){
                              servers[j] = t2 ;
                              v++ ;
                          }
                   }
                   printf("%lld\n",s);
              }
          }
          return 0 ;
      }