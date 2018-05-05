#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main(){
	vector<int> a7a;
  int k,kk;
  for(int i=0;i<3;i++){
     scanf("%d",&k);
     a7a.push_back(k);
  }
  sort(a7a.begin(), a7a.end());
  if(a7a[0]==1){ // 1-x-x
     printf("YES\n");
  }
  else if(a7a[0]==2 && a7a[1]==2){ // 2-2-x
     printf("YES\n");
  }
  else if(a7a[0]==2 && a7a[1]==4 && a7a[2]==4){ // 2-4-4
    printf("YES\n");
  }
  else if(a7a[0]==3 && a7a[1]==3 && a7a[2]==3){  // 3-3-3
    printf("YES\n");
  }
  else printf("NO\n");
	return 0;
}