#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

vector<int>p,q,p_fns,q_fns,final_fns;
int st[800005];

void _erase(int p,int l, int r ,int index){
   if(index<l || index>r) return ;
   if(l==r){
      st[p]=1;
      return ;
   }
   int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   _erase(lft,l,mid,index);
   _erase(rgt,mid+1,r,index);
   st[p] = st[lft]+st[rgt];
}

int _query(int p,int l,int r ,int index){
   if(index < l) return 0;
   if(l==r) return st[p];
   if(r<=index) return st[p];
   int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   return _query(lft,l,mid,index)+_query(rgt,mid+1,r,index);
}

void build(int p,int l,int r){
   if(l==r){
     st[p]=1;
     return ;
   }
   int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   build(lft,l,mid);build(rgt,mid+1,r);
   st[p]=st[lft]+st[rgt];
}

void __erase(int p,int l,int r,int index){
    if(index<l || index>r) return ;
    if(l==r) {
        st[p]=0;
        return ;
    }
   int lft,rgt,mid;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   __erase(lft,l,mid,index);__erase(rgt,mid+1,r,index);
   st[p]=st[lft]+st[rgt];
}

int __query(int p,int l,int r , int num){
    if(l==r) return l ;
    int lft,rgt,mid;
    lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
    if(num>st[lft]) return __query(rgt,mid+1,r,num-st[lft]);
    return __query(lft,l,mid,num);
}


int main(){
    int n,x,index;scanf("%d",&n);


    for(int i=0;i<n;i++){
         scanf("%d",&x);
         p.push_back(x);
         p_fns.push_back(p[i]-_query(1,0,n-1,p[i]-1));
         _erase(1,0,n-1,p[i]);
    }
    memset(st,0,sizeof(st));
    for(int i=0;i<n;i++){
         scanf("%d",&x);
         q.push_back(x);
         q_fns.push_back(q[i]-_query(1,0,n-1,q[i]-1));
         _erase(1,0,n-1,q[i]);
    }



    for(int i=0;i<n;i++){
     final_fns.push_back(p_fns[i]+q_fns[i]);
    }
    for(int i=n-1;i>=0;i--){
    index = n-i;
        if(final_fns[i]>=index){
                final_fns[i] -= index ;
                if(i>0) final_fns[i-1]+=1;
        }
    }


    build(1,0,n-1);
    for(int i=0;i<n;i++){
         int ans = __query(1,0,n-1,final_fns[i]+1);
         __erase(1,0,n-1,ans);
         printf("%d ",ans);
    }
    printf("\n");


    return 0 ;
}