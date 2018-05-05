#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
int st_lft[400010],st_rgt[400010];
map<ll,int> mp;
set<ll> sett;
vector<ll>arr;
void _add(int st[],int p,int l,int r,int index){
   if(index<l||index>r) return ;
   if(l==r){
      st[p]++;
      return ;
   }
   int lft,rgt,mid,mn;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   _add(st,lft,l,mid,index);
   _add(st,rgt,mid+1,r,index);
   st[p]=st[lft]+st[rgt];
}

void _remove(int st[],int p,int l,int r,int index){
  if(index<l||index>r) return ;
  if(l==r){
     st[p]--;
     return ;
  }
   int lft,rgt,mid,mn;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   _remove(st,lft,l,mid,index);
   _remove(st,rgt,mid+1,r,index);
   st[p]=st[lft]+st[rgt];
}


int query(int st[],int p,int l,int r,int i,int j){
   if(i>r || j<l)   return 0;
   if(i<=l && j>=r) return st[p];
   int lft,rgt,mid,mn;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   return query(st,lft,l,mid,i,j)+query(st,rgt,mid+1,r,i,j);
}


int main(){
 int n,m=0;
 ll k,a,ans=0,inv=0; scanf("%d%I64d",&n,&k);
 for(int i=0;i<n;i++){
     scanf("%I64d",&a);
     arr.push_back(a);
     sett.insert(a);
 }
 set<ll>::iterator it=sett.begin();
 for(;it!=sett.end();it++){
     mp[*it]=m++;
 }

 ll l=0,r=n-1;

 while(l<r){
     inv += query(st_rgt,1,0,sett.size()-1,0,mp[arr[r]]-1);
     if(arr[r]<arr[l]) inv++;
     _add(st_rgt,1,0,sett.size()-1,mp[arr[r]]);
     if(inv>k) break;
     r--;
 }

 if(l==r) r++;
 _add(st_lft,1,0,sett.size()-1,mp[arr[l]]);
 while(r<n){
     if(inv>k){
          inv -= query(st_rgt,1,0,sett.size()-1,0,mp[arr[r]]-1);
          inv -= query(st_lft,1,0,sett.size()-1,mp[arr[r]]+1,sett.size()-1);
          _remove(st_rgt,1,0,sett.size()-1,mp[arr[r]]);
          r++;
     }else{
          ans += n-r;
          if(l+1==r){
            inv -= query(st_rgt,1,0,sett.size()-1,0,mp[arr[r]]-1);
            inv -= query(st_lft,1,0,sett.size()-1,mp[arr[r]]+1,sett.size()-1);
            _remove(st_rgt,1,0,sett.size()-1,mp[arr[r]]);
            r++;
          }

            l++;
            _add(st_lft,1,0,sett.size()-1,mp[arr[l]]);
            inv+= query(st_lft,1,0,sett.size()-1,mp[arr[l]]+1,sett.size()-1);
            inv+= query(st_rgt,1,0,sett.size()-1,0,mp[arr[l]]-1);
     }
 }
 printf("%lld\n",ans);
 return 0;
}