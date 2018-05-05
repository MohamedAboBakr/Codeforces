#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int ones[300001] = {0};
vector <int> zeroes ;
int main(){

   int n , k ,z=0; scanf("%d%d",&n,&k);
   int arr[n+1] ;
   for(int i=1 ; i<=n ; i++){
     scanf("%d",&arr[i]);
     if(arr[i] == 1) ones[i] = 1+ones[i-1] ;
     else{
            z++ ;
            zeroes.push_back(i);
            ones[i] = ones[i-1];
     }
   }
   zeroes.push_back(n+1);
   if( z == n){
         k = min(k,n);
         printf("%d\n" , k);
         for(int o=1 ; o<=k ; o++){
            printf("%d " , 1);
         }
         for(int o=1 ; o<= n-k ; o++){
            printf("%d " , 0);
         }
         return 0 ;
   }
   k = min(k , z);
   int l , r ;
   int i = 1 , j = zeroes[k]-1 , t=0 , h=k;
   int mx = 0 ;
   h++ ;
   while(j<=n){
        int ones_seg = ones[j]-ones[i-1] ;
        if(ones_seg > mx){
             mx = ones_seg ;
             l = i ; r = j ;
        }
        
        if(j == n) break ;
        i = zeroes[t]+1 ;
        j = zeroes[h]-1 ;
        t++ ; h++ ;
   }

   for(int o=l ; o<=r ; o++){
        arr[o] |= 1 ;
   }

   printf("%d\n" , k+mx);
   for(int o=1 ; o<=n ; o++){
     printf("%d " , arr[o]);
   }
   return 0 ;
}