#include<bits/stdc++.h>
    using namespace std;
    typedef long long ll ;

    int main(){
          int n ; scanf("%d",&n);
          if(n%4){
              printf("===\n");
              return 0 ;
          }
          string s ; cin >> s ;
          int A=0 , C = 0 , G = 0 , T = 0 ;
          for(int i=0 ; i<n; i++){
              if(s[i] == 'A') A++;
              else if(s[i] == 'C') C ++ ;
              else if(s[i] == 'G') G++ ;
              else if(s[i] == 'T') T ++ ;
          }


          int eq = n/4 ;
          if(A>eq || C > eq || G > eq || T > eq){
            printf("===\n");
              return 0 ;
          }
          A = eq-A ;
          C = eq-C ;
          G = eq -G ;
          T = eq-T ;
          for(int i=0 ; i<n ; i++){
              if(s[i] != '?') printf("%c",s[i]);
              else {
                  if(A){
                      printf("A"); A-- ;
                  }else if(C)
                  {
                      printf("C"); C-- ;

                  }
                  else if(G)
                  {
                      printf("G"); G-- ;

                  }
                  else if(T)
                  {
                      printf("T"); T-- ;

                  }
              }
          }
          printf("\n");
          return 0 ;
      }