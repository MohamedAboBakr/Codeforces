#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;


void add_(vector<int>&ans, int part, int strt){
    int ss = strt+1;
    part--;
    while(part--){
       ans.push_back(ss++);
    }
    ans.push_back(strt);
}

int main(){
	int n,a,b,x=-1,y=-1;
	scanf("%d%d%d",&n,&a,&b);
  if((n%a)==0){
  	x=n/a;
  	y=0;
  }
  else if((n%b)==0){
    x=0;
    y=n/b;
  }
  else{
  	for(int i=1; (i*a)<n ; i++){
         if((n-i*a)%b==0){
         	 x=i;
         	 y=(n-i*a)/b;
         	 break;
         }
  	}
  }

  if(x==-1 && y==-1){
  	printf("-1\n");
  	return 0;
  }
  vector<int>ans;
  int strt=1;
  for(int i=0;i<x;i++,strt+=a){
    add_(ans, a, strt);
  }
  for(int i=0;i<y;i++,strt+=b){
    add_(ans, b, strt);
  }
  for(int i=0;i<n;i++){
   printf("%d",ans[i]);
   if(i== n-1) printf("\n");
   else printf(" ");
  }
	return 0;
}