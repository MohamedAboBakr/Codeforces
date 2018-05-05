#include<bits/stdc++.h>
using namespace std;
#define M 200005
typedef long long ll ;

ll mxx ;
int flag = 0 ;
bool visit[200005];

struct node{
    ll val ;
    int id ;
    ll sum ;
    ll maxsum ;
    vector <int> connect;
}tree[M] ;


void solve(int id){
     visit[id] = true ;
     int sz =  tree[id].connect.size() ;
     bool rec = false ;
     int cnt = 0 ;
     ll sum = 0;
     vector < ll > temp ; temp.push_back(-1  * 10000000000 );temp.push_back(-1  * 10000000000 );
     for(int i=0 ; i< sz ; i++){
           if(visit[tree[id].connect[i]]) continue ;
           rec = true ; cnt++;
           solve(tree[id].connect[i]);
           ll tst = tree[tree[id].connect[i]].maxsum ;
           if(tst >= temp[0]){ temp[1] = temp[0] ; temp[0] = tst;}
           else if( tst > temp[1]) temp[1] = tst ;
           sum += tree[tree[id].connect[i]].sum ;
     }
     if(cnt == 0){
          tree[id].sum = tree[id].val ;
          tree[id].maxsum = tree[id].val;
     }else if(cnt > 1){
           flag = 1 ;
           mxx = max(mxx , temp[0]+temp[1]);
           tree[id].sum = sum + tree[id].val ;
           tree[id].maxsum = max(tree[id].sum , temp[0]);
     }else {
           tree[id].sum = sum + tree[id].val ;
           tree[id].maxsum = max(tree[id].sum , temp[0]);
     }
}

int main(){
    mxx = -1  * 10000000000 ;
   int n , u,v ;
   scanf("%d",&n);
    for(int i=1 ; i<=n ; i++){
         scanf("%lld",&tree[i].val);
         tree[i].id = i ;
         tree[i].sum = 0 ;
         tree[i].maxsum  =-1  * 10000000000 ;
    }
    for(int i=0 ; i<n-1 ; i++){
         scanf("%d%d",&u,&v);
         tree[u].connect.push_back(v);
         tree[v].connect.push_back(u);
    }

    solve(1);
   /* for(int i=1 ; i<=n ; i++){
        printf("%lld **\n " , tree[i].maxsum);
    }*/
    if(flag == 0) printf("Impossible\n");
    else printf("%lld\n",mxx);
  return 0 ;
}