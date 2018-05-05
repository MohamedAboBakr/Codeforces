#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000
#define pi pair< int  , int >
typedef long long ll ;

char forest[1000][1000] ;
bool visit[1000][1000];
int dist[1000][1000];
int r,c,sPath,ans;
int iS , jS , iE , jE ;
queue <pi> q ;

void read(){
   scanf("%d%d",&r,&c); getchar();
   for(int i=0 ; i<r ; i++){
      for(int j=0 ; j<c ; j++){
           forest[i][j] = getchar();
           if(forest[i][j] == 'S') { iS = i ; jS = j ;}
           else if(forest[i][j] == 'E') { iE = i ; jE = j ;}
           dist[i][j] = MAX ;
      }
      getchar();
   }
}

void go(int i , int j , int d){
   if(i<0 || j<0 || i >= r || j>= c) return ;
   if(forest[i][j] == 'T') return ;
   if(visit[i][j]) return ;
   visit[i][j] = true ;
   dist[i][j] = d+1 ;
   q.push({i,j});
}

void dijkstra(int ie , int je){
          visit[ie][je] = true ;
          dist[ie][je] = 0 ;
          q.push({ie,je});

          while(!q.empty()){
                pi pii = q.front();
                q.pop();
                go(pii.first+1 , pii.second , dist[pii.first][pii.second]);
                go(pii.first-1 , pii.second , dist[pii.first][pii.second]);
                go(pii.first   , pii.second+1 , dist[pii.first][pii.second]);
                go(pii.first   , pii.second-1 , dist[pii.first][pii.second]);
          }
}

void solve(){
     for(int i=0 ; i<r ; i++){
        for(int j=0 ; j<c ; j++){
             if(dist[i][j] <= dist[iS][jS] && forest[i][j]>='0' && forest[i][j]<='9') ans += forest[i][j] -'0' ;
        }
     }
}

int main(){
  read();
  dijkstra(iE , jE);
  solve();
  printf("%d\n",ans);
  return 0 ;
}