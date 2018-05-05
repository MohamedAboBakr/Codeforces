#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <math.h>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll ;


int main() {
   int n , k  ;
   cin >> n >> k ;
   int arr[n+1] ;
   vector<int> nums(k+1 , 0);
   for(int i=1; i <= n ; i++){
     scanf("%d",&arr[i]);
     if(arr[i] <= k){
        nums[arr[i]] ++ ;
     }
   }
   vector<int> fact(k+1 , 0);
   fact[1] = nums[1] ;
   for(int i=2 ; i<= k ; i++){
       fact[i] = nums[i]+nums[1] ;
   }

   for(int i=2 ; i*i <= k ; i++){
       for(int j=i ; j*i <= k ; j++){
           if(j == i) fact[j*i] += nums[i];
           else fact[j*i] += nums[i] + nums[j];
       }
   }

/*
   for(int i=1 ; i<= k ; i++){
     printf("%d\n",fact[i]);
   }
*/
   int Llcm = 1 , mx = 0 , fl =0 ;
   for(int i = 1 ; i <= k ; i++){
      if(fact[i] > mx){
            Llcm = i ;
            mx = fact[i];
      }
   }

   stack<int> index ;
   for(int i=n; i >= 1 ; i--){
       if(Llcm % arr[i] == 0){
          index.push(i);
       }
   }

   printf("%d %d\n",Llcm , mx);
   while(!index.empty()){
       if(fl) printf(" ");
       printf("%d" , index.top());
       index.pop(); fl++;
   }
  printf("\n");
   return 0 ;
}