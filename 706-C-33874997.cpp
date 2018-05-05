#include<bits/stdc++.h>
    #include<string.h>
    #include<stdio.h>
	using namespace std;
	typedef long long ll;
	
  
	int main(){	
		int n; scanf("%d",&n);
    ll ci[n];
    for(int i=0;i<n;i++) scanf("%lld",&ci[i]);
    string s1; cin >> s1;
    string s2 = s1; reverse(s2.begin(),s2.end()); 

    ll c1=0L,c2=ci[0];

    for(int i=1;i<n;i++){
    	string ss; cin>>ss;
    	string ss2=ss; reverse(ss2.begin(),ss2.end());

    	ll cc1 = 1e16L,cc2=1e16L;
      
      if(ss>=s1) cc1 =min(cc1,c1);
      if(ss>=s2) cc1= min(cc1,c2);

      if(ss2>=s1) cc2=min(cc2,c1+ci[i]);
      if(ss2>=s2) cc2=min(cc2,c2+ci[i]);
      
      s1=ss; s2=ss2;
      c1=cc1; c2=cc2;

    }
    if(min(c1,c2)==1e16L) printf("-1\n");
    else printf("%lld\n",min(c1,c2));
		return 0;
	}