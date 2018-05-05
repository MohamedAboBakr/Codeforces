#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int friends[5];


int main(){


  int m,a,b; scanf("%d",&m);
  while(m--){
      scanf("%d%d",&a,&b);
      friends[a-1]++;
      friends[b-1]++;
  }

  for(int i=0;i<5;i++){
     if(friends[i] > 2 || friends[i] < 2) {
         printf("WIN\n");
         return 0;
     }
  }
 printf("FAIL\n");
  return 0 ;
}