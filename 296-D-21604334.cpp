#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

ll sum ;
ll dist[500][500];
ll remve[500];
ll sssp[500];
int n ;
void floydWarshall(int V)
{
    int i, j, k;
    for (k = 0; k < V; k++)
    {
        int across = remve[k] ;
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                    int v = remve[j];
                    int u = remve[i];
                    dist[v][u] = min(dist[v][u] , dist[v][across] + dist[across][u]);
                    if(i<=k && j<=k) sssp[k] += dist[v][u] ;
            }
        }
    }
}


void read(){
  scanf("%d",&n);
  for(int i=0 ; i<n ; i++){
     for(int j=0 ; j<n ; j++){
         scanf("%lld",&dist[i][j]);
     }
  }

  for(int i=n-1 ; i>=0; i--){
     scanf("%lld",&remve[i]); remve[i]-- ;
  }

}

void print(){
   for(int i=n-1 ; i>=0 ; i--){
       printf("%lld%s",sssp[i],(i==0)?"\n":" ");
   }
}

int main(){

  read();
  floydWarshall(n);
  print();
  return 0 ;
}