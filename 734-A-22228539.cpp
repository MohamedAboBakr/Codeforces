#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

void solve(){

}

int main(){
  int n ; scanf("%d\n",&n);
  char g[100005];
  scanf("%s",g);
  int m=0,d=0 ;
  for(int i=0;i<n;i++){
     if(g[i]=='A') m++;
     else d++ ;
  }
  if(m==d) printf("Friendship\n");
  else if(m>d) printf("Anton\n");
  else printf("Danik\n");
  return 0 ;
}