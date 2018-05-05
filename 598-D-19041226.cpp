#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
char chrs[1000][1000];
int  flag[1000][1000];
int  groups[1000001] = {0};
int  grop = 0 ;
void get_grp(int i, int j , int n , int m){
     if(i>=n || j>=m || i<0 || j<0) return ;
     if(chrs[i][j] == '*'){
         groups[grop]++;
         return ;
     }

     else if(chrs[i][j] == '.' && flag[i][j] == 0){
         flag[i][j] = grop ;
         get_grp(i-1 , j , n , m);
         get_grp(i+1 , j , n , m);
         get_grp(i , j+1 , n , m);
         get_grp(i , j-1 , n , m);
     }

}

void search_(int n , int m){
  for(int i=0 ; i<n ; i++){
     for(int j=0 ; j<m ; j++){
         if(chrs[i][j] == '.' && flag[i][j] == 0){
             grop++;
             get_grp(i,j,n,m);
         }
     }
  }
}

int main(){

  int n , m , k , x,y;
  cin >> n >> m >> k ;
  getchar();
  for(int i=0 ; i<n ; i++){
     for(int j=0 ; j<m ; j++){
        chrs[i][j] = getchar();
        flag[i][j]= 0 ;
     }
     getchar();
  }

  search_(n,m);
  for(int i=0 ; i<k ; i++){
    cin >> x >> y ;
    printf("%d\n",groups[flag[x-1][y-1]]);
  }
  return 0 ;
}