#include<bits/stdc++.h>
	using namespace std;

	int main(){
		int n,wi,hi;
		vector<int> w,h;
		int mx1=-1,mx2=-1,cntmx=0,tot_w=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
       scanf("%d %d",&wi,&hi);
       w.push_back(wi); tot_w+=wi;
       h.push_back(hi);
       if(mx1==-1){
       	 mx1=hi;
       	 cntmx=1;
       }
       else if(hi==mx1){
         cntmx++;
       }
       else if(hi>mx1){
       	 mx2=mx1;
       	 mx1=hi;
       	 cntmx=1;
       }
       else{
       	 mx2 = max(mx2,hi);
       }
		}
		for(int i=0;i<n;i++){
       wi=tot_w-w[i];
       if(h[i]<mx1) hi=mx1;
       else{
       	 if(cntmx>1) hi=mx1;
       	 else hi=mx2;
       }
       printf("%d",wi*hi);
       if(i<n-1) printf(" ");
		}
		printf("\n");
		return 0;
	}