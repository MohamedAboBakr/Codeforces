#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main(){
  int n,t; scanf("%d",&n);
  int arr[n];
  vector < pair < int  , int > > ind ;
  scanf("%d",&arr[0]); t = 1 ;
  for(int i=1;i<n ; i++){
     scanf("%d",&arr[i]);
     if(arr[i] != arr[i-1]){
         ind.push_back({arr[i-1],t});
         t=1;
     } else t++ ;
  }
  ind.push_back({arr[n-1],t});
  int ans[100005]={0};
  ans[0]=ind[0].second ;
  if(ind.size()>=1){
        if(abs(ind[1].first-ind[0].first) <= 1) ans[1] = ind[1].second+ind[0].second ;
        else ans[1]=ind[1].second ;
  }
  for(int i=2 ; i<ind.size();i++){
      if(abs(ind[i].first-ind[i-1].first)>1) ans[i] = ind[i].second;
      else{
         if(ind[i].first == ind[i-2].first) ans[i] = ans[i-1]+ind[i].second ;
         else  ans[i] = ind[i-1].second+ind[i].second ;
      }
  }

  int mx = 0;
  for(int i=0; i<ind.size() ; i++){
      mx = max(mx,ans[i]);
  }
  printf("%d\n",mx);
  return 0 ;
}