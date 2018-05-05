#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int arr[100005],d[100005];
int flag[100005];
int n,m ;

int BS(int mid){
    memset(flag,0,sizeof(flag));
    int subj = 0 ;
    int days = 0 ;
    for(int i=mid ; i>0;i--){
         if(!arr[i]||flag[arr[i]]){
             if(days>0)days -- ;
             continue ;
         }

         subj++;
         days += d[arr[i]];
         flag[arr[i]] = 1 ;
    }

    return subj==m && days<=0 ;
}

int solve(){
    int l=1 , r = n ,mid;
    int ans = -1 ;
    while(l<=r){
          mid = (l+r)/2;
         if(BS(mid)){
                r = mid-1 ;
                ans = mid ;
         }
         else l = mid+1;
    }
    return ans ;
}
int main(){
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
  for(int i=1;i<=m;i++) scanf("%d",&d[i]);
  printf("%d\n",solve());
  return 0 ;
}