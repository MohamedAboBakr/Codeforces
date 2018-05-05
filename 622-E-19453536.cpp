#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define N 500005
vector<int> adj_list[N] ;
vector<int> depths ;

void dfs(int v , int fa , int d){

    int sz = adj_list[v].size();
    int flag = 0 ;
    for(int i=0; i<sz ; i++){
         if(adj_list[v][i] == fa) continue ;
         flag = 1 ;
         dfs(adj_list[v][i] , v , d+1);
    }
    if(flag == 0) depths.push_back(d);
}

int get_mxtime(int v , int fa){
     depths.clear();
     dfs(v,fa,0);
     sort(depths.begin() , depths.end());
     int sz = depths.size();
     for(int i=1 ; i<sz ; i++){
        depths[i] = max(depths[i] , depths[i-1]+1);
     }
     return depths.back();
}

int brute_force(){
   int ans = 0 ;
   int root = 0 ;
   int sz = adj_list[root].size();
   for(int i=0 ; i<sz ; i++){
       ans = max(ans , get_mxtime(adj_list[root][i] , 0)+1);
   }
   return ans ;
}


int main(){
   int n ,u,v; scanf("%d",&n);
   for(int i=0 ; i<n-1 ; i++){
      scanf("%d%d",&u,&v);
      u--; v--;
      adj_list[u].push_back(v);
      adj_list[v].push_back(u);
   }
   int ans = brute_force();
   printf("%d\n" , ans);
   return 0 ;
}