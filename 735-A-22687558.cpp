#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main(){
   int n , k ; scanf("%d%d",&n,&k);
   string seq ; cin >> seq ;
   int G,T ;
   for(int i=0;i<n;i++){
       if(seq[i]=='G') G = i ;
       else if(seq[i]=='T') T = i ;
   }

   int v ;
   if(G<T) v = 1 ;
   else v = -1 ;
   for(int i=G ; i<n && i>=0 ; i += (v*k)){
        if(seq[i] == 'T'){
             printf("YES\n");
             return 0 ;
        }else if(seq[i] == '#'){
           printf("NO\n");
             return 0 ;
        }
   }
    printf("NO\n");
   return 0 ;
}