#include<bits/stdc++.h>
using namespace std;
typedef long double ll ;
#define EPS 1e-9
ll arr[80];
ll curr[80];
int n,t,num;
void solve(){

 for(int k=0;k<t;k++){
     int glass = 1;
     curr[1] = 1.0 ;
     for(int i=1;i<=n;i++){
           bool flag = false ;
           for(int j=1;j<=i;j++,glass++){
               arr[glass] += curr[glass];
               if(arr[glass] > 1.0 ){
                     ll val = arr[glass] - 1.0;
                     arr[glass] = 1.0 ;
                     flag = true ;
                     curr[glass+i]   += val / 2.0 ;
                     curr[glass+i+1] += val / 2.0 ;
               }
               curr[glass] = 0 ;
           }
           if(flag == false) break ;
     }
 }
}

int countGlasses(){
       int ans = 0 ;
       for(int i=1 ; i <= (n*(n+1)/2) ; i++){
          if(abs(arr[i]-1.0) < EPS) ans++ ;
       }
       return ans ;
}

int main(){

    scanf("%d%d",&n,&t);
    num = n*(n+1)/2 ;
    solve();
    int ans = countGlasses() ;
    printf("%d\n",ans);
  return 0 ;
}