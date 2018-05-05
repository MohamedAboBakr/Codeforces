#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int pow_2[18];
ll st[524300],a[131075];
int flag[524300];

void build(int p , int l , int r){
   if(l == r){
        st[p] = a[l];
        flag[p] = 1 ;
        return ;
   }

   int lft,rgt,mid,mn;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   build(lft,l,mid);
   build(rgt,mid+1,r);
   if(flag[lft]==1){
            st[p]=st[lft]|st[rgt];
            flag[p] = -1 ;
   }else {
            st[p]=st[lft]^st[rgt];
            flag[p] = 1 ;
   }
}

void update(int p,int l , int r , int index , ll val){
       if(index>r || index<l)   return;
       if(l==r) {
            st[p]=val;
            return ;
       }
   int lft,rgt,mid,mn;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   update(lft,l,mid,index,val);
   update(rgt,mid+1,r,index,val);
   if(flag[lft]==1){
            st[p]=st[lft]|st[rgt];
   }else {
            st[p]=st[lft]^st[rgt];
   }
}


int main(){
  pow_2[0]=1 ;
  for(int i=1 ; i<18 ; i++){
      pow_2[i] = 2*pow_2[i-1];
  }
  int n,m,sz,p; scanf("%d%d",&n,&m);
  ll b ;
  sz = pow_2[n];
  for(int i=0;i<sz;i++){
     scanf("%lld",&a[i]);
  }
  build(1,0,sz-1);
  while(m--){
     scanf("%d%lld",&p,&b);
     update(1,0,sz-1,p-1,b);
     printf("%lld\n",st[1]);
  }
  return 0 ;
}