#include<bits/stdc++.h>
    using namespace std;
    typedef long long ll ;
   /* int n ;
    int temp[200005];
    int dp[200005][2];*/
  /*  int solve(int index , int* last , int rest){
        if(index == n){
             if(temp[n-1]==0) *last = 0 ;
             else *last = 1 ;
             return 0 ;
        }

        if(dp[rest][index%2] != -1) return dp[res][index%2];
        if(temp[rest][index%2] == -1) return solve(index+1 , *last , rest);
        int lst = dp[res][(index+1)%2] ;
        int sol1 = solve(index+1 , *last , rest) + lst;
        sol1 += group
    }
    */
    int main(){
          int n , k ; scanf("%d%d",&n,&k);
          int pos = 0  , neq = 0 ,t;
          int temp[n+1]; memset(temp , 0 , sizeof temp);

          for(int i= 0 ; i<n ; i++){
             scanf("%d",&t);
             if(t < 0){
                   temp[i] = 1 ;
                   neq ++ ;
             }else pos++ ;

          }
           if(neq ==0){
              printf("0\n");
              return 0 ;
           }
          if(neq > k){
              printf("-1\n");
              return 0 ;
          }

          int rest = k-neq ;


          vector < pair < int ,  pair < int  , int > > > tp ;
          int i=0 ;
          for(;i<n; i++){
               if(temp[i] == 1) break ;
          }
          int f = 1 ;
          int j=i,jj,d=0;
          for( ; i<n ; i++){
              if(temp[i] == 1){
                    if(f == -1){
                        jj = i ;
                        tp.push_back( { d , {j,jj}});
                        d=0;
                        f *= -1 ;
                    }

              }
              else {
                 if(f == 1){
                      j = i ;
                      f *= -1 ;
                 }
                 d++ ;
              }
          }
          int lstt = d ;
         // printf("%d\n",lstt);
          sort(tp.begin(), tp.end());

          for(int j=0;j<tp.size();j++){
              int dd = tp[j].first;
              if(rest < dd) break;
              rest -= dd ;
              int ff,lls ; ff = tp[j].second.first ; lls = tp[j].second.second ;
              for(int kk = ff ; kk<= lls ; kk++){
                   temp[kk] = 1 ;
              }
          }

          if(rest >= lstt){
              for(int j=n-1 ; temp[j]!=1 ; j--){
                  temp[j] = 1 ;
              }
          }

          int ans = 0 ;
          f = 1 ;
          for(int i=0; i<n ; i++){
              if(temp[i]==1){
                   if(f==1){
                     ans++ ;
                     f*= -1;
                   }
              }else {
                 if(f == -1){
                     ans++ ;
                     f *= -1 ;
                 }
              }

                       }
          printf("%d\n",ans);
          return 0 ;
      }