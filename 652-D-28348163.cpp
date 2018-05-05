#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

struct segment{
   ll l,r;
   int index;
   bool operator<(const segment& seg)const {
      if(l!=seg.l) return l<seg.l;
      return r>seg.r;
  }
};
segment segs[200010];
int ans[200010],st[800010];
vector<ll>endd;

void add(int p,int l,int r,int index){
    if(index<l || index>r) return;
    if(l==r){
        st[p]++;
        return ;
    }
    int lft,rgt,mid,mn;
    lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
    add(lft,l,mid,index);
    add(rgt,mid+1,r,index);
    st[p]=st[lft]+st[rgt];
}

int sum(int p,int l,int r,int i,int j){
     if(i>r || j<l)return 0;
     if(i<=l && j>=r) return st[p];
     int lft,rgt,mid,mn;
     lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
     return sum(lft,l,mid,i,j)+sum(rgt,mid+1,r,i,j);
}


int main(){
  int n,index; scanf("%d",&n);
  ll l,r;
  for(int i=0;i<n;i++){
     scanf("%lld%lld",&l,&r);
     segs[i].l=l;
     segs[i].r=r;
     segs[i].index=i;
     endd.push_back(r);
  }
  sort(segs,segs+n);
  sort(endd.begin(),endd.end());
  vector<ll>::iterator it;
  for(int i=n-1;i>=0;i--){
       it = lower_bound(endd.begin(),endd.end(),segs[i].r);
       index = it-endd.begin();
       ans[segs[i].index] = sum(1,0,n-1,0,index-1);
       add(1,0,n-1,index);
  }
  for(int i=0;i<n;i++){
     printf("%d\n",ans[i]);
  }
  return 0;
}