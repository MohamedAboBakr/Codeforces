#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	int n; scanf("%d",&n);
	int a[n];
	int sm=0, mn_pos_odd=INT_MAX, mx_neg_odd=INT_MIN;
	for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    if(a[i]>0) sm += a[i];
    if(a[i]>0 && a[i]%2) mn_pos_odd = min(mn_pos_odd, a[i]); 
    if(a[i]<0 && a[i]%2) mx_neg_odd = max(mx_neg_odd, a[i]);
	}
	int ans;
	if(sm%2) 	ans=sm;
	else ans = max(sm-mn_pos_odd , sm+mx_neg_odd);
	printf("%d\n",ans);
	return 0;
}