#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll arr[2000][2000] ;

int main(){
 int n ; scanf("%d",&n);
 for(int i=0 ; i<n; i++) for(int j=0 ; j<n ; j++) scanf("%lld",&arr[i][j]);
 for(int i=0 ; i<n ; i++){
    int sm_ed = 1 ;
    for(int j=0 ; j<n ; j++) {
         if(i==j && arr[i][j]!=0 || (i!=j && arr[i][j]==0)) {
              printf("NO\n");
              return 0 ;
         } if(arr[i][j] != arr[j][i]) {
              printf("NO\n");
              return 0 ;
         }

         if( i!=j && arr[i][j] < arr[i][sm_ed]) sm_ed = j ;
    }

    for(int k=0 ; k<n ; k++){
        if(i!=k && abs(arr[i][k]-arr[k][sm_ed])!= arr[i][sm_ed]){
              printf("NO\n");
              return 0 ;
        }
    }
 }

 printf("YES\n");
 return 0 ;
}