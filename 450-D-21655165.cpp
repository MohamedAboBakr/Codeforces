#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define Max 100002
#define MAXX 1e18
vector < pair < pair < int , int >  , ll > > adj_list[Max];
ll dist[Max];
int flag[Max];
int times[Max];
bool visit[Max];
int n,m,k ;
int clse ;

void dijkstra(){
     queue<int> q ;
     dist[1] = 0 ;
     q.push(1);
     visit[1] = true ;
     while(!q.empty()){
          int u = q.front() ;
          q.pop();

          for(int i=0 ; i<adj_list[u].size(); i++){
               int v = adj_list[u][i].first.first;
               ll  w = adj_list[u][i].second;
               if(dist[v] > dist[u] + w){
                     times[v] = 1 ;
                     dist[v] = dist[u]+w ;
                     if(!visit[v]){ visit[v] = true;
                     q.push(v); }
               } else if(dist[v]==dist[u] + w){
                    times[v]++;
               }
          }
          visit[u] = false ;
     }
}

int main(){
  for(int i=0; i<Max ; i++){
     dist[i] = MAXX;
  }
  clse = 0 ;
  scanf("%d%d%d",&n,&m,&k);
  int u,v,tp; ll w ;
  for(int i=0 ; i<m ; i++){
      scanf("%d%d%lld",&v,&u,&w);
      adj_list[v].push_back({{u,0},w});
      adj_list[u].push_back({{v,0},w});
  }

 /* for(int i=1 ; i<6 ; i++){
     printf("***** %lld\n",dist[i]);
  } */
  for(int i=0 ; i<k ; i++){
      scanf("%d%lld",&v,&w);
      adj_list[v].push_back({{1,1},w});
      adj_list[1].push_back({{v,1},w});
  }
  dijkstra();

  for(int i=0 ; i<adj_list[1].size() ; i++){
       v  = adj_list[1][i].first.first ;
       tp = adj_list[1][i].first.second ;
       w  = adj_list[1][i].second ;
       ll sssp = dist[v];
       if(tp == 1){
            if(w > sssp) clse ++ ;
            else if(w == sssp){
                 if(times[v] > 1){ clse++; times[v]-- ;}
                 else if(times[v]==1 && flag[v]==1) {clse++; times[v]-- ;}
            }
       }else {
            if(w == sssp) {
                 flag[v] = 1 ;
                 times[v]-- ;
            }
       }
  }
  printf("%d\n",clse);
  return 0 ;
}