#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll a[100010],st[400010],f[400010];

void build(int p,int l,int r){
        if(l==r){
            st[p]=a[l];
            return ;
        }
       int lft,rgt,mid,mn;
       lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
       build(lft,l,mid);
       build(rgt,mid+1,r);
       st[p]=max(st[lft],st[rgt]);
}

void add(int p,int l,int r,int i,int j,ll mx){
        if(i>r || j<l)return;
        if(i<=l && j>=r){
            f[p]=1;
            st[p]=mx;
            return;
        }
       int lft,rgt,mid,mn;
       lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
       if(f[p]==1){
          st[lft]=st[p];
          st[rgt]=st[p];
          f[lft]=1; f[rgt]=1;
       }
       add(lft,l,mid,i,j,mx);
       add(rgt,mid+1,r,i,j,mx);
       st[p]=max(st[lft],st[rgt]);
       f[p]=0;
}

ll maxx(int p,int l,int r,int i,int j){
       if(i>r || j<l)return 0;
       if(f[p]==1) return st[p];
       if(i<=l && j>=r) return st[p];
       int lft,rgt,mid,mn;
       lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
       return max(maxx(lft,l,mid,i,j),maxx(rgt,mid+1,r,i,j));
}


int main(){
     int n,m;scanf("%d",&n);
     ll w,h,ans;
     for(int i=0;i<n;i++){
         scanf("%lld",&a[i]);
     }
     build(1,0,n-1);
     scanf("%d",&m);
     while(m--){
        scanf("%lld%lld",&w,&h);w--;
        ans = maxx(1,0,n-1,0,w);
        printf("%lld\n",ans);
        add(1,0,n-1,0,w,ans+h);
     }
     return 0;
}