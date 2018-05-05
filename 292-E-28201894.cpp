#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int> pi ;

ll a[100010],b[100010],st[400010],c[400010];


void _copy(int p,int l , int r , int i , int j , int index){
     if(i>r || j<l) return ;
     if(i<=l && j>=r){
         st[p] = index;
         c[p] = i ;
         return ;
     }
   int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   if(st[p]!= -1){
   st[lft]=st[p];c[lft]=c[p];
   st[rgt]=st[p];c[rgt]=c[p];
   }
   _copy(lft,l,mid,i,j,index);
   _copy(rgt,mid+1,r,i,j,index);
   st[p] = -1 ;
   c[p]=-1;
}

pi query(int p , int l , int r , int index){
     if(index>r || index<l)   return pi(-1,-1) ;
     if(st[p]!= -1){
             int diff = index-c[p];
             return pi(1,st[p]+diff);
     }
    if(l==r) return pi(2,index);
   int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   pi p1,p2 ;
   p1 = query(lft,l,mid,index); p2 = query(rgt,mid+1,r,index);
   if(p1.first == -1) return p2 ;
   return p1;
}

int main(){
  memset(st,-1,sizeof(st));
  int n,m,t,x,ln,y;
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++){
    scanf("%lld",&a[i]);
  }
  for(int i=0;i<n;i++){
    scanf("%lld",&b[i]);
  }
  while(m--){
     scanf("%d",&t);
     if(t==1){
        scanf("%d%d%d",&x,&y,&ln);
        _copy(1,0,n-1,y-1,y+ln-2,x-1);
     }else{
        scanf("%d",&y);
        pi ans = query(1,0,n-1,y-1);
        if(ans.first==1) printf("%lld\n",a[ans.second]);
        else printf("%lld\n",b[ans.second]);
     }
  }

  return 0 ;
}