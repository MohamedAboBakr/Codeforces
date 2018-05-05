#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<ll,ll> pll ;
typedef pair<int,pll> ppll ;

struct point{
  ll x,y;
  bool operator<(const point& p)const {
      if(x!=p.x) return x<p.x;
      return y<p.y;
  }
};
point p1[200010],p2[200010];
ll st[800010];
vector< int > reqs;

void _add_remove(int p , int l , int r , ll x , ll y){
    if(x<l || x > r) return ;
    if(l==r){
        st[p]=y;
        return ;
    }
     int lft,rgt,mid;
     lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
     _add_remove(lft,l,mid,x,y);
     _add_remove(rgt,mid+1,r,x,y);
     st[p] = max(st[lft],st[rgt]);
}

int _find(int p,int l,int r, ll x , ll y){
    if(p2[r].x<=x || st[p]<=y) return -1;
    if(l == r) return l ;
    int lft,rgt,mid;
    lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
    int chk = _find(lft,l,mid,x,y);
    if(chk!=-1) return chk;
    return _find(rgt,mid+1,r,x,y);
}


int main(){
 memset(st,-1,sizeof(st));
 int n; scanf("%d",&n);getchar();
 ll x,y;
 char opr[7];
 for(int i=0; i<n;i++){
    scanf("%s%lld%lld",opr,&x,&y);getchar();
    p1[i].x=x;p1[i].y=y;
    p2[i].x=x;p2[i].y=y;
    if(opr[0]=='a') reqs.push_back(0);
    else if(opr[0]=='f') reqs.push_back(1);
    else reqs.push_back(2);
 }

 sort(p2,p2+n);

 for(int i=0;i<n;i++){
     if(reqs[i]==0) _add_remove(1,0,n-1,lower_bound(p2,p2+n,p1[i])-p2,p1[i].y);
     else if(reqs[i]==2) _add_remove(1,0,n-1,lower_bound(p2,p2+n,p1[i])-p2,-1);
     else{
        int ans = _find(1,0,n-1,p1[i].x,p1[i].y);
        if(ans == -1) printf("-1\n");
        else printf("%lld %lld\n",p2[ans].x,p2[ans].y);
     }
 }
 return 0;
}