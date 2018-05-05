#include<bits/stdc++.h>
using namespace std ;

int main(){
  int n,m;
  scanf("%d%d",&n,&m);
  if(n>=m){
    printf("%d\n",n-m);
    return 0;
  }
  int mn1=0,mn2=0;
  int n1=n,m1=m;
  while(m1>n){
     if(m1%2){
        mn1++;
        m1+=1;
     }
     mn1++;
     m1 /= 2;
  }
  mn1+=n-m1;

  while(true){
     n1*=2;
     mn2++;
     if(n1>=m) break;
  }
  mn2+=n1-m;
  printf("%d\n",min(mn1,mn2));
  return 0;
}