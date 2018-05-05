#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int>pi;
map<int,set<pi> > ans;
int st[4000010],mxx[4000010],mnx[4000010];

void _add(int p,int l,int r,int num){
  if(l==r){
        mxx[p]=num;
        mnx[p]=num;
        st[p]=1;
     return;
  }
  int lft,rgt,mid,mn;
  lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
  if(st[lft]==mid-l+1)_add(rgt,mid+1,r,num);
  else _add(lft,l,mid,num);
  st[p]++;
  if(st[lft]==0){
        mxx[p]=mxx[rgt];
        mnx[p]=mnx[rgt];
    }
    else if(st[rgt]==0){
        mxx[p]=mxx[lft];
        mnx[p]=mnx[lft];
    }else {
        mxx[p]=max(mxx[lft],mxx[rgt]);
        mnx[p]=min(mnx[lft],mnx[rgt]);
    }
}


void _min_max(int p,int l,int r,int *i,int j,int *mn,int *mx,int k){
    if(l>j) return;
    //if((abs(*mx-mxx[p])>k&&(*mn!=mnx[p])) || (abs(*mn-mnx[p])>k&& *mx!=mxx[p])) return;
    if(abs(*mx-mnx[p])<=k && abs(*mn-mxx[p])<=k && mxx[p]-mnx[p]<=k){
            *i=l;
            *mx=max(*mx,mxx[p]);
            *mn=min(*mn,mnx[p]);
             return;
    }
    if(l==r) return ;
    int lft,rgt,mid;
    lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
    _min_max(rgt,mid+1,r,i,j,mn,mx,k);
    if(*i<=mid+1) _min_max(lft,l,mid,i,j,mn,mx,k);
}


int main(){
 int n,k,hi,maxx=0; scanf("%d%d",&n,&k);
 for(int i=0;i<n;i++){
     scanf("%d",&hi);
     _add(1,0,n-1,hi);
     int mn=hi,mx=hi,j=i,ln;
     _min_max(1,0,n-1,&j,i,&mn,&mx,k);
     ln = i-j+1;
     ans[ln].insert(pi(j,i));
     maxx=max(maxx,ln);
 }

 printf("%d %d\n",maxx,ans[maxx].size());
 set<pi>::iterator itt = ans[maxx].begin();
 for(; itt!=ans[maxx].end();itt++){
    printf("%d %d\n",(*itt).first+1,(*itt).second+1);
 }
 return 0;
}