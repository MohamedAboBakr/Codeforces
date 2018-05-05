#include<bits/stdc++.h>
using namespace std;
typedef pair< int ,int > pi ;
typedef pair<int , pi > ppi ;

int maxx[4000001],open[4000001],close[4000001];
char str[1000001];

void build(int p , int l , int r){
   if(l == r){
        maxx[p] = 0 ;
        if(str[l]=='(') open[p]=1;
        else close[p] = 1 ;
        return ;
   }

   int lft,rgt,mid,mn;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   build(lft,l,mid);
   build(rgt,mid+1,r);
   mn = min(open[lft],close[rgt]);
   maxx[p] = maxx[lft]+maxx[rgt]+mn*2;
   open[p] = open[lft]+open[rgt]-mn;
   close[p] = close[lft]+close[rgt]-mn;
}

ppi quiry(int p , int l , int r , int i , int j){
    if(i>r || j<l)   return ppi(0,pi(0,0));
    if(i<=l && j>=r) return ppi(maxx[p],pi(open[p],close[p]));
    int lft,rgt,mid;
    ppi p1,p2,p3 ;
    int mn,mx,o,c;
    lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
    p1 = quiry(lft,l,mid,i,j);
    p2 = quiry(rgt,mid+1,r,i,j);
    mn = min(p1.second.first,p2.second.second);
    mx = p1.first+p2.first+mn*2 ;
    o = p1.second.first+p2.second.first-mn;
    c = p1.second.second+p2.second.second-mn;
    return ppi(mx,pi(o,c));
}


int main(){
  int n,q,i,j;
  scanf("%s",str); getchar();
  n = strlen(str);
  build(1,0,n-1);
  scanf("%d",&q);
  while(q--){
      scanf("%d%d",&i,&j);
      printf("%d\n",quiry(1,0,n-1,i-1,j-1).first);
  }
  return 0 ;
}