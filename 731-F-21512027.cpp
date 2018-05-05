#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define Max1 200003
#define Max2 200002

ll arr[Max1] , sum[Max1] ;
ll maxx ;
int main(){

    int n,a ; scanf("%d",&n);
    for(int i=0; i<n ; i++){
         scanf("%d",&a);
         arr[a]++ ;
    }

    for(int i=1 ; i< Max1 ; i++){
         sum[i] = arr[i]+sum[i-1];
       //  if(i < 20) printf();
    }

    for(ll i=1 ; i< Max1 ; i++){
          ll curr_ans = 0;
          if(arr[i] == 0) continue ;
          for(ll j=i ; j< Max1 ; j+= i){
              curr_ans += (sum[min(j+i-1,(ll)Max2)] - sum[j-1])*j ;
          }
          maxx = max(maxx,curr_ans);
    }
    printf("%lld\n",maxx);
  return 0 ;
}