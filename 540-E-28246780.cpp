#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int> pi ;
typedef pair<int,pi> ppi ;

map<ll,ll> mp;
map<ll,ll> mp1;
vector<ll> A,B,index;
ll st[4000100];


ll query(int p,int l,int r,ll indx){
         if(indx<l)   return 0L;
         if(indx>=r) return st[p];
         int lft,rgt,mid,mn;
         lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
         return query(lft,l,mid,indx)+query(rgt,mid+1,r,indx);

}


void update(int p, int l , int r ,ll indx){
         if(indx>r || indx<l)   return;
         if(l == r) {
             st[p]++;
             return ;
         }
         int lft,rgt,mid,mn;
         lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
         update(lft,l,mid,indx);
         update(rgt,mid+1,r,indx);
         st[p] = st[lft]+st[rgt];
}


int main(){
        int n,k=0; scanf("%d",&n);
        ll a,b,num1,num2,ans=0L,ind,seg1,seg2;
        for(int i=0;i<n;i++){
             scanf("%lld%lld",&a,&b);a--;b--;
             if(mp.find(a)!=mp.end()) num1=mp[a];
             else num1=a;
             if(mp.find(b)!=mp.end()) num2=mp[b];
             else num2=b;
             mp[a] = num2;
             mp[b] = num1;
        }

        map<ll,ll>::iterator it = mp.begin();
        for(; it!=mp.end();it++){
             //printf("%lld  --  %lld\n",it->first,it->second);
             A.push_back(it->second);
             B.push_back(it->second);
             index.push_back(it->first);
             mp1[it->second] = k++;
        }

        sort(A.begin(),A.end());
        vector<ll>::iterator vit;
        for(int i=0 ; i<A.size() ;i++){
              seg1 = abs(B[i]-index[i])-1;
              seg2 = abs(i-mp1[index[i]])-1;
              ans += seg1-seg2 ;
              vit = lower_bound(A.begin(),A.end(),B[i]);
              ind = vit-A.begin();
              int sm = query(1,0,A.size()-1,ind);
              ans += (ind-sm);
              update(1,0,A.size()-1,ind);
        }

        printf("%lld\n",ans);
        return  0 ;
}