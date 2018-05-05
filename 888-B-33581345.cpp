#include<bits/stdc++.h>
	using namespace std;

	int main(){
	  int l=0,r=0,u=0,d=0;
	  int n,mx=0;
	  string s;
	  cin >> n >> s;
	  for(int i=0;i<n;i++){
	  	if(s[i]=='L') l++;
	  	else if(s[i]=='R') r++;
	  	else if(s[i]=='U') u++;
	  	else d++;
	  	mx= min(d,u)*2+min(l,r)*2;
	  }
	  printf("%d\n",mx); 
		return 0;
	}