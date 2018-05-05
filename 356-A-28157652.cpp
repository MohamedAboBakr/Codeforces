#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int st[1200010];
int conq[1200010];

void build(int p,int l,int r){
    if(l==r){
        st[p] = l;
        return ;
    }
   int lft,rgt,mid,mn;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   build(lft,l,mid);
   build(rgt,mid+1,r);
   st[p] = -1 ;
}

void query(int p , int l , int r , int i, int j , int win){
    if(i>r || j<l)   return;
   // if(st[p]!= -1 && conq[st[p]]!= -1) return ;
    if(l==r){
         if(st[p]==win) return;
         if(conq[st[p]] == -1)conq[st[p]]=win;
         st[p] = win ;
         return ;
    }

    if(st[p]!=-1){
         if(st[p]==win) return ;
         if(conq[st[p]] == -1) conq[st[p]]=win;
         st[p] = win ;
         return ;
    }
   int lft,rgt,mid,mn;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   query(lft,l,mid,i,j,win);
   query(rgt,mid+1,r,i,j,win);
   if(i<=l && j>=r) st[p] = win;
}


int main(){
    int n,m,i,j,w,winner; scanf("%d%d",&n,&m);
    memset(conq,-1,sizeof(conq));
    build(1,0,n-1);
    while(m--){
        scanf("%d%d%d",&i,&j,&w);
        query(1,0,n-1,i-1,j-1,w-1);
        if(m==0) winner = w-1 ;
    }
    conq[winner]=-1 ;
    for(int k=0 ; k<n ; k++){
        printf("%d ",conq[k]+1);
    }
    printf("\n");
    return 0 ;
}