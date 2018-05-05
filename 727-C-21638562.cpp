#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main(){
  int n ; scanf("%d",&n);
  fflush(stdout);
  int i1,i2,i3 ;
  int arr[n+1] ;

  printf("? 1 2\n"); fflush(stdout);
  scanf("%d",&i1);   fflush(stdout);
  printf("? 1 3\n"); fflush(stdout);
  scanf("%d",&i2);   fflush(stdout);
  printf("? 2 3\n"); fflush(stdout);
  scanf("%d",&i3);   fflush(stdout);

  arr[2] = (i1-i2+i3)/2 ;
  arr[3] = i3 - arr[2] ;
  arr[1] = i1 - arr[2] ;

  for(int i=4 ; i<= n ; i++){
       printf("? 1 %d\n",i); fflush(stdout);
       scanf("%d",&i1);      fflush(stdout);
       arr[i] = i1-arr[1] ;
  }

  printf("!");
  for(int i=1 ; i<=n ; i++){
      printf(" %d",arr[i]);
  }

  printf("\n");
  return 0 ;
}