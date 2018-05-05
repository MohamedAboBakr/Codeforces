#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int sum[4000005],t[1000005];
ll A[1000005];
map<ll , int> nums1,nums2;
int c1,c2;

int add(int p , int l , int r , int index){
    if(index>r || index<l)   return sum[p];
    if(l==r && index == r ) {
        sum[p]++;
        return sum[p];
    }
   int lft,rgt,mid,mn;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   return sum[p] = add(lft,l,mid,index)+add(rgt,mid+1,r,index);
}


int query(int p , int l , int r , int i , int j){
   if(i>r || j<l)   return 0;
   if(i<=l && j>=r) return sum[p];
   int lft,rgt,mid,mn;
   lft = 2*p ; rgt = lft+1; mid = (l+r)/2;
   return query(lft,l,mid,i,j)+query(rgt,mid+1,r,i,j);
}


int main(){

 int n ; scanf("%d",&n);
 ll ans = 0 ;
 for(int i=0;i<n;i++){
     scanf("%lld",&A[i]);
     if(i>0){
         if(A[i]<A[i-1]) c1++;
         if(A[i]>A[i-1]) c2++;
     }
     nums1[A[i]]++;
     t[i] = nums1[A[i]];
 }
 if(c1==n-1 || c2==n-1){
     printf("0\n");
     return 0 ;
 }
 for(int i=n-1; i>0 ; i--){
     nums2[A[i]]++;
     add(1,0,n-1,nums2[A[i]]);
     if(t[i-1]>1)ans+= query(1,0,n-1,1,t[i-1]-1);
 }
 printf("%lld\n",ans);
 return 0 ;
}