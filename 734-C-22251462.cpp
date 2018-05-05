#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

 ll arr1[200005][2] ;
 ll arr2[200005][2] ;

int BS(ll key , ll n){
    int l=1 , r = n ,mid;
    if(arr2[1][1]>key) return -1 ;
    int ans = -1 ;
    while(l<=r){
          mid = (l+r)/2;
         if(arr2[mid][1]>key){
                r = mid-1 ;
         }
         else {
                l = mid+1;
                ans = mid ;
         }
    }
    return ans ;
}

int main(){
 ll n,m,k,x,s;
 scanf("%lld%lld%lld",&n,&m,&k); scanf("%lld%lld",&x,&s);
 ll tm1 =0,tm2=1000000000;

 for(int i=0;i<m;i++){
    scanf("%lld",&arr1[i][0]);
 }

 for(int i=0;i<m;i++){
    scanf("%lld",&arr1[i][1]);
 }

 for(int i=1;i<=k;i++){
    scanf("%lld",&arr2[i][0]);
 }

 for(int i=1;i<=k;i++){
    scanf("%lld",&arr2[i][1]);
 }

 tm1 = n*x ;
 //printf(" t1 %lld \n",tm1);
 int index = BS(s,k);
 if(index!= -1) {
    //  printf("index1 %d\n",index);
      ll val = arr2[index][0];
      if(n>val){
         tm1 = min(tm1,(n-val)*x) ;
       //  printf("tm2 %lld\n",tm2);
      }
      else {
        tm1 = 0 ;
      }
 }

for(int i=0;i<m;i++){
      if(s>=arr1[i][1]){
          int index = BS(s-arr1[i][1],k);
          if(index != -1){
             ll val = arr2[index][0];
             if(n>val){
              //   printf("%d  %d ****\n",i , index);
               tm1 = min(tm1,(n-val)*arr1[i][0]);
             } else tm1 = 0 ;
          }else {
              tm1 = min(tm1,n*arr1[i][0]);
          }
      }
  }

  printf("%lld\n",tm1);
  return 0 ;
}