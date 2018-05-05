#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;


int main(){

   int a1,a2,a3,a4,a5,a6 ;
   scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6);
   int ans=0;
   for(int i=1 ; i<= min(a1,a3) ; i++ , a2++){
       ans += (a2 * 2)+1;
   }
   ans += (a2*2)*abs(a1-a3);

   for(int i=1 ; i<= min(a4,a6) ; i++ , a5++){
       ans += (a5 * 2)+1;
   }

   printf("%d\n",ans);
   return 0 ;
 }