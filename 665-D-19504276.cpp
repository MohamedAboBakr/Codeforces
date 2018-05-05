#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int primes[2000001]={0};
int main(){

  for(int i=4 ; i<= 2000000 ; i+=2){
      primes[i] = 1 ;
  }
  for(int i=3 ;  i<= 2000000 ; i+=2){
      if(primes[i] == 0){
          for(int j=i+i ; j<= 2000000 ; j+= i){
              primes[j] = 1 ;
          }
      }
  }

  int ones = 0 , twos=0;
  int mx =  0 ;
  int n ; scanf("%d",&n);
  int arr[n] ;
  for(int i=0 ; i<n ; i++){
     scanf("%d",&arr[i]);
     ones = (arr[i] == 1) ? ones+1 : ones ;
     twos = (arr[i] == 2) ? twos+1 : twos ;
  }

  int x1 , x2 ;
  int single ;
  for(int i=0 ; i<n ; i++){
     if(primes[arr[i]] == 0) {

         mx = max(mx ,1) ;
         single = arr[i] ;
     }
     int mxx ;
     for(int j=i+1 ; j<n ; j++){
         if(primes[arr[i] + arr[j]] == 0 ){
            if(arr[i] == 1 && arr[j] == 1) mxx = ones ;
            else if(arr[i] == 1 || arr[j] == 1) mxx = ones+1 ;
             else mxx = 2 ;
            if(mxx > mx){
                    x1 = arr[i] ;
                    x2 = arr[j] ;
                    mx = mxx ;
            }
         }
     }
  }

  if(mx == 0){
      printf("1\n%d\n" , arr[0]);
      return 0 ;
  }
  if(ones+twos > mx && twos == 1){
      printf("%d\n",ones+twos);
      for(int i=0 ; i<ones ; i++){
         printf("1 ");
      }
      for(int i=0 ; i<twos ; i++){
         printf("2 ");
      }
      printf("\n");
      return 0 ;
  }

  if(mx == 1){
      printf("1\n%d\n" , single);
  }else{

     printf("%d\n" , mx);
     if(x1==1 || x2 == 1){

           for(int i=0; i<ones ; i++){
              printf("1 ");
           }
           if(mx > ones){
              if(x1 != 1) printf("%d" , x1);
              else printf("%d" , x2);

           }

           printf("\n");
     }else{
        printf("%d %d\n" , x1,x2);
     }
   }
  return 0 ;
}