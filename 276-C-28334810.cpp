#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

vector<ll>a,b;
int st[800010];

void add(int p,int l,int r ,int i,int j){
   if(i>r || j<l)   return;
   if(i<=l && j>=r){
            st[p]++;
            return ;
   }
   int lft,rgt,mid,mn;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   st[lft]+=st[p];
   st[rgt]+=st[p];
   add(lft,l,mid,i,j);
   add(rgt,mid+1,r,i,j);
   st[p]=0;
}

void solve(int p,int l,int r){
   if(l==r){
      b.push_back(st[p]);
      return ;
   }
   int lft,rgt,mid,mn;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   st[lft]+=st[p];
   st[rgt]+=st[p];
   solve(lft,l,mid);
   solve(rgt,mid+1,r);
}

int main(){
 int n,q,l,r;
 ll x,ans=0;
 scanf("%d%d",&n,&q);
 for(int i=0;i<n;i++){
     scanf("%lld",&x);
     a.push_back(x);
 }
 sort(a.begin(),a.end(),greater<ll>());
 while(q--){
    scanf("%d%d",&l,&r);
    add(1,0,n-1,l-1,r-1);
 }
 solve(1,0,n-1);
 sort(b.begin(),b.end(),greater<ll>());
 for(int i=0;i<b.size();i++){
     ans += b[i]*a[i];
 }
 printf("%lld\n",ans);
 return 0;
}