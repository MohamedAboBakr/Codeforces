#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

vector<int>a,ans;
int _real[4000010],_fake[4000010],val[4000010];

void _delete(int p,int l,int r,int index){
    if(l==r){
         val[p]=-1;
        _real[p]=0;
        return;
    }
    int lft,rgt,mid,mn;
    lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
    if(_real[lft]>index) _delete(lft,l,mid,index);
    else _delete(rgt,mid+1,r,index-_real[lft]);
    _real[p]-=1;
}

void _insert(int p,int l,int r,int index,int num){
    if(l==r){
         val[p]=num;
         _real[p]=1;
         _fake[p]=1;
         return;
    }
    int lft,rgt,mid,mn;
    lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
    if(_fake[lft]==mid-l+1)_insert(rgt,mid+1,r,index-(mid-l+1),num);
    else _insert(lft,l,mid,index,num);
    _real[p]+=1;
    _fake[p]+=1;
}

void _final(int p,int l,int r){
     if(_real[p]==0) return;
     if(l==r){
        ans.push_back(val[p]);
        return ;
     }
    int lft,rgt,mid,mn;
    lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
    _final(lft,l,mid);
    _final(rgt,mid+1,r);
}

int main(){
  int n,m,ai,ev,ln=0,index,o=0; scanf("%d%d",&n,&m);
  for(int i=0;i<m;i++){
      scanf("%d",&ai);
      a.push_back(ai);
  }
  vector<int>::iterator it;
  for(int i=0;i<n;i++){
     scanf("%d",&ev);
     if(ev<0){
        it=lower_bound(a.begin(),a.end(),ln);
        index=it-a.begin();
        if(index==a.size()) index--;
        else if(a[index]>ln) index--;
        ln -= index+1;
        for(int k=0;k<=index;k++){
             _delete(1,0,n-1,a[k]-1-k);
        }
     }else{
        _insert(1,0,n-1,o,ev);
        o++;
        ln++;
     }
  }
  _final(1,0,n-1);
  for(int i=0;i<ans.size();i++){
     printf("%d",ans[i]);
  }
  if(ans.size()==0)printf("Poor stack!");
  printf("\n");
  return 0 ;
}