#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdio.h>
#include<bits/stdc++.h>

using namespace std;

#define N 100001

int arr[N] ;
int sizeOfcomb[N] ;
int connected_comp = N ;
int flag[N] = {0};
int circle = 0 , root;


// disjoint sets functions

void initialize(){
  for(int i=0 ; i<N ; i++){
     arr[i] = i ;
     sizeOfcomb[i] = 1 ;
  }
}

int Find(int a){
   if(arr[a] == a) return a;
   // path compression
   return arr[a] = Find(arr[a]);
}


bool Is_connect(int a , int b){
    int parent1 = Find(a);
    int parent2 = Find(b);
    if(parent1 == parent2) return true;
    return false ;
}

void Union(int a , int b){
    if(Is_connect(a,b)) {
            root = Find(a);
            flag[root] = 1 ;
            return ;
    }
    connected_comp -- ;
    int parent1 = Find(a);
    int parent2 = Find(b);
   // printf("%d %d %d %d\n" , a , b , parent1 , parent2);
    if(flag[parent2] == 1) flag[parent1] = 1;
    else if(flag[parent1] == 1)flag[parent2] =1 ;
    arr[parent1] = parent2 ;
    sizeOfcomb[parent2] += sizeOfcomb[parent1] ;

}

int sizeOfelem_comp(int a){
    return sizeOfcomb[Find(a)];
}



int main(){

  initialize();
  int n , m ,x ,y , check = 0 ;
  cin >> n >> m ;
  for(int i=0 ; i<m ; i++){
    cin >> x >> y ;
    Union(x,y);
  }

 for(int i=1 ; i<=n ;i++){

     int root = Find(i);
    // printf("%d\n" , root);
     if(root == i){
        if(flag[root] != 1){
             check++;
        }
     }
 }

 printf("%d\n" , check);
}