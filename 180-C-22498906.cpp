#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
char mssg[100005];
int n ;
int lower[100010];
int upper[100010];
int main(){
  scanf("%s",mssg);
  n = strlen(mssg);
  int minn = 100000 ;
  for(int i=0;i<n;i++){
      if(mssg[i]>='a'&&mssg[i]<='z') {
            lower[i+1] = 1+lower[i];
            upper[i+1] = upper[i];
      }
      else {
            lower[i+1] = lower[i];
            upper[i+1] = upper[i]+1;
      }
  }
  int lowchars = lower[n] ;
  if(lowchars==0 || lowchars==n){
      printf("0\n");
      return 0 ;
  }

  for(int i=0;i<=n ; i++){
       minn = min(minn , lower[i]+upper[n]-upper[i]);
  }
  printf("%d\n",minn);
  return 0 ;
}