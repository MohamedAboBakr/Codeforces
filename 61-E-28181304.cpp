#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
vector<ll> A,B;
int st[4000100];


int query(int p,int l,int r,int index){
     if(index<l)   return 0;
     if(index>=r) return st[p];
     int lft,rgt,mid,mn;
     lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
     return query(lft,l,mid,index)+query(rgt,mid+1,r,index);

}


void update(int p, int l , int r ,int index){
     if(index>r || index<l)   return;
     if(l == r) {
         st[p]++;
         return ;
     }
     int lft,rgt,mid,mn;
     lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
     update(lft,l,mid,index);
     update(rgt,mid+1,r,index);
     st[p] = st[lft]+st[rgt];
}

int main(){
 int n; scanf("%d",&n);
 ll ans = 0,a,ind;
 for(int i=0;i<n;i++){
     scanf("%I64d",&a);
     A.push_back(a);
     B.push_back(a);
 }
 sort(A.begin(),A.end());
 vector<ll>::iterator index;
 for(int i=0;i<n;i++){
      index = lower_bound(A.begin(),A.end(),B[i]);
      ind = index-A.begin();
      //cout << ind << "\n";
      int sm = query(1,0,n-1,ind);
      ans += (i-sm)*(ind-sm);
      update(1,0,n-1,ind);
 }
 printf("%I64d\n",ans);
 return 0 ;
}