#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int> pi ;
typedef pair<int,pi> ppi ;

ll st[400010],a[100010];
int num[400010],t[400010];


void build(int p , int l , int r){
   if(l == r){
        st[p] = a[l] ;
        num[p] = a[l];
        t[p]=1;
        return ;
   }
   int lft,rgt,mid,p1,p2;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   build(lft,l,mid);
   build(rgt,mid+1,r);
   st[p]=__gcd(st[lft],st[rgt]);
   if(num[lft]==-1&&num[rgt]==-1){
       num[p]=-1;
       t[p]=0;
       return ;
   }
   if(num[lft]==num[rgt]){
       num[p]=num[lft];
       t[p]=t[lft]+t[rgt];
       return ;
   }

   if(num[lft]==-1){
       if(st[p]%num[rgt]==0){
          num[p] = num[rgt];
          t[p] = t[rgt];
          return ;
       }
       num[p] = -1;
       t[p] =0;
       return ;
   }
   if(num[rgt]==-1){
       if(st[p]%num[lft]==0){
          num[p] = num[lft];
          t[p] = t[lft];
          return ;
       }
       num[p] = -1;
       t[p] =0;
       return ;
   }

   if(st[p]%num[lft]==0 && st[p]%num[rgt]==0){
            if(num[lft]<num[rgt] && num[rgt]%num[lft]==0){
                num[p] = num[lft];
                t[p]=t[lft];
            }else if(num[lft]>num[rgt] && num[lft]%num[rgt]==0) {
                num[p] = num[rgt];
                t[p]=t[rgt];
            }else{
                 num[p]=-1;
                 t[p]=0;
             }

        return ;
   }

   if(st[p]%num[lft]==0){
            num[p] = num[lft];
            t[p]=t[lft];
            return ;
   }

   if(st[p]%num[rgt]==0){
            num[p] = num[rgt];
            t[p]=t[rgt];
            return ;
   }

   num[p]=-1;
   t[p]=0;
}


ppi query(int p,int l , int r , int i , int j){
  if(i>r || j<l)   return ppi(0,pi(-1,0));
  if(i<=l && j>=r){
        return ppi(st[p],pi(num[p],t[p]));
  }
  int lft,rgt,mid,mn;
  ppi p1,p2;
  lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
  p1 = query(lft,l,mid,i,j);
  p2 = query(rgt,mid+1,r,i,j);
  ll sm = __gcd(p1.first,p2.first);
  int n1,n2,t1,t2;
  n1 = p1.second.first;   n2 = p2.second.first;
  t1 = p1.second.second;  t2 = p2.second.second;

  if(n1==-1 && n2==-1){
       return ppi(sm,pi(-1,0));
  }
  if(n1==n2){
       return ppi(sm,pi(n1,t1+t2));
  }
  if(n1==-1){
       if(sm%n2==0){
          return ppi(sm,pi(n2,t2));
       }
       return ppi(sm,pi(-1,0));
  }
  if(n2==-1){
      if(sm%n1==0){
         return ppi(sm,pi(n1,t1));
      }
      return ppi(sm,pi(-1,0));
  }
  if(sm%n1==0 && sm%n2==0){
      if(n1<n2  && n2%n1==0){
         return ppi(sm,pi(n1,t1));
      }else if(n2<n1 && n1%n2==0){
         return ppi(sm,pi(n2,t2));
      }else return ppi(sm,pi(-1,0));
  }

  if(sm%n1==0)  return ppi(sm,pi(n1,t1));
  if(sm%n2==0)  return ppi(sm,pi(n2,t2));
  return ppi(sm,pi(-1,0));
}


int main(){
  int n,t,l,r; scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%lld",&a[i]);
  }
  build(1,0,n-1);
  scanf("%d",&t);
  while(t--){
      scanf("%d%d",&l,&r);
      printf("%d\n",r-l+1-query(1,0,n-1,l-1,r-1).second.second);
  }
  return 0 ;
}