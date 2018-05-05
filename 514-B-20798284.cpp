#include <bits/stdc++.h>
using namespace std;
typedef long double ld ;

int main(){

   map<ld , int> slope ;
   int inf = 0 ;
   int n , x0 , y0 , x,y ; scanf("%d%d%d",&n,&x0,&y0);
   for(int i=0 ; i<n ; i++){
      scanf("%d%d",&x,&y);
      if(x == x0) inf=1 ;
      else slope[1.0*(y-y0)/(1.0*(x-x0))]++;
   }
   printf("%d\n",slope.size()+inf);
   return 0 ;
 }