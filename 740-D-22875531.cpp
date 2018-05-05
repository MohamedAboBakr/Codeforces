#include<bits/stdc++.h>
using namespace std;
#define MAX 200005
#define MIN -1*100000000
typedef long long ll ;

pair< ll , ll > toBS[MAX] ;
vector < pair< ll , ll > > tree[MAX];
ll dist[MAX] , value[MAX] , ans[MAX] , control[MAX];
int index , n;

ll dfs(int u , ll d){
      dist[u] = d ;
      int bs = lower_bound(toBS , toBS+index , pair< ll , ll >(dist[u]-value[u] , -1*100000000))-toBS;
      if(bs != index){
           control[u]++;
           control[toBS[bs].second]--;
      }
      ll anss = 0 ;
      toBS[index++] = {dist[u] , u};
      for(int i=0 ; i< tree[u].size() ; i++){
            int v = tree[u][i].second ; ll  w = tree[u][i].first ;
            anss += dfs(v , dist[u]+w);
      }
      index-- ;
      ans[u] = anss ;
      return anss+control[u];
}


int main(){
    scanf("%d",&n);
    int p;
    ll w ;
    for(int i=1 ; i<=n ; i++){
         scanf("%d",&value[i]);
    }

    for(int i=2 ; i<=n ; i++){
         scanf("%d%lld",&p,&w);
         tree[p].push_back({w,i});
    }

    dfs(1,0);
    for(int i=1;i<=n ; i++){
        printf("%lld%s",ans[i],(i==n)?"\n":" ");
    }
    return 0 ;
}