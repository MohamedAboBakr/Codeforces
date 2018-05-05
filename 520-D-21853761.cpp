#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

map< pair < int , int > , int  > pos ;
map< int , pair < int , int > > top ;
map< int , pair < int , int > > cubes ;
int arr[100005];
ll mod = 1000000009;

bool checkleft(int x , int y){
     if(pos.find({x-1,y+1})!=pos.end()&&pos.find({x-2,y})==pos.end()&& pos.find({x-1,y})==pos.end()) return false;
     return true ;
}

bool checkright(int x , int y){
     if(pos.find({x+1,y+1})!=pos.end()&&pos.find({x+2,y})==pos.end()&&pos.find({x+1,y})==pos.end()) return false;
     return true ;
}

bool checkup(int x , int y){
     if(pos.find({x,y+1})!=pos.end()&&pos.find({x-1,y})==pos.end()&&pos.find({x+1,y})==pos.end()) return false;
     return true ;
}

bool check(int x,int y){
   if(pos.size()==0) return true;
   if(pos.find({x,y})==pos.end()) return true ;
   if(checkleft(x,y)&&checkright(x,y)&&checkup(x,y)) {
        top[pos[{x,y}]]={x,y} ;
        return true;
   }
   return false ;
}

void solve(int m){
   int c=0 ,f=1;
   map< int , pair < int , int > >::iterator it1;
   map< int , pair < int , int > >::reverse_iterator it2;
   while(c < m){
        int num,x,y;
        if(f == -1){
             it1 = top.begin();
             num = it1->first ;
             x = it1->second.first;
             y = it1->second.second ;
             f *= -1 ;
        } else {
             it2 = top.rbegin();
             num = it2->first ;
             x = it2->second.first;
             y = it2->second.second ;
             f *= -1 ;
        }
             arr[c++] = num ;
             pos.erase({x,y});
             top.erase(num);
             if(pos.find({x-1,y-1})!=pos.end()&&check(x-1,y-1)) top[pos[{x-1,y-1}]]={x-1,y-1};
             if(pos.find({x,y-1})!=pos.end()&&check(x,y-1)) top[pos[{x,y-1}]]={x,y-1};
             if(pos.find({x+1,y-1})!=pos.end()&&check(x+1,y-1)) top[pos[{x+1,y-1}]]={x+1,y-1};
             if(pos.find({x-1,y})!=pos.end()&&!check(x-1,y)) top.erase(pos[{x-1,y}]);
             if(pos.find({x-2,y})!=pos.end()&&!check(x-2,y)) top.erase(pos[{x-2,y}]);
             if(pos.find({x+1,y})!=pos.end()&&!check(x+1,y)) top.erase(pos[{x+1,y}]);
             if(pos.find({x+2,y})!=pos.end()&&!check(x+2,y)) top.erase(pos[{x+2,y}]);
   }
}

int main(){
  int m,x,y; scanf("%d",&m);
  for(int i=0 ; i< m ; i++){
      scanf("%d%d",&x,&y);
      pos[{x,y}] = i ;
      cubes[i]={x,y};
  }

  for(int i=0;i<m ; i++){
      int x = cubes[i].first ;
      int y = cubes[i].second ;
      check(x,y);
   }
  solve(m);
 /*  for(int i=0 ; i<m ; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");*/
  ll ans = 0 ;
  for(int i=0;i<m;i++){
     ans = (arr[i]+(m*ans)%mod)%mod;
  }
  printf("%lld\n",ans);
  return 0 ;
}