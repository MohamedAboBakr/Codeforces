#include <cstdio>
#include <vector>
#include <string.h>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define N 300000
int arr[N] ;
int index[N] ;
int flag[N] ;
map <int , int > pairs ;

int main(){
  int n , m ;
  scanf("%d%d" , &n , &m);
  for(int i=0 ; i<n ; i++){
      scanf("%d",&arr[i]);
      index[arr[i]] = i ;
  }
  int a,b,j1,j2;
  int mn , mx ;
  for(int i=0 ; i<m ; i++){
       scanf("%d%d" , &a , &b);
       j1 = index[a] ; j2 = index[b];
       mx = max(j1,j2);
       mn = min(j1,j2);
       pairs[mx] = max(mn , pairs[mx]);
       flag[mx] = 1 ;
  }

  if(n == 1){
       printf("1\n");
       return 0 ;
  }

  ll ans = 0 ;
  int l=0 , r ;
  ll B = 1 ;
  for(int i=1 ; i<n ; i++){
        int last = pairs[i];
        if(flag[i] == 1 && last >= l){
            l = last+1 ;
            ans += (i-l) ;
        }else{
            ans += (i-l);
        }
  }
  printf("%lld\n" , ans+n);
  return 0 ;
}