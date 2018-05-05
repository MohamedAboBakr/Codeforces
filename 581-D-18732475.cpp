#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <stdio.h>
#include<bits/stdc++.h>

using namespace std;

#define longlong ll ;


int main(){

   int x1 , y1 , x2 , y2 , x3 , y3 ;
   int max1 , min1 , max2 , min2 , max3 , min3 ;
   int len[3][2] , w , l;
   int max_ = 0 , biggest , ind[2];
   for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<2 ; j++){
           cin >> len[i][j] ;
           if(len[i][j] > max_) {
            max_ = len[i][j] ;
            biggest = i ;
           }
        }
   }

   if(len[biggest][0] == max_){
       w = max_  ;
       l = len[biggest][1];
   }
   else{
       w = max_  ;
       l = len[biggest][0];
   }
   char arr[max_][max_];
   char ch[3] = {'A' , 'B' , 'C'};
   int check_area = 0 , c=0 ;
   for(int i=0; i<3 ; i++){
    if(i != biggest) {
        ind[c++] = i ;
        check_area += len[i][0]*len[i][1] ;
    }
   }

   if(check_area != w*(w-l)){
     printf("-1\n");
     return 0 ;
   }

   int r =0 , flag = 0;
   for(int i=0 ; i<3 ; i++){
      if(i != biggest){
        if(len[i][0] == max_ || len[i][1] == max_){
            r += len[i][0] + len[i][1] - max_ ;
        }
        else{
            flag = 1 ;
            break;
        }
      }
   }
   if(flag == 0 && r == w-l){
      printf("%d\n" , max_);

      for( int i=0 ; i<max_ ; i++){
         for( int j=0 ; j< l ; j++){
            arr[i][j] = ch[biggest];

         }
      }

    int  index =    ( biggest + 1 ) %3 ;
    int t = len[index][0]+len[index][1] - max_ + l ;
     for(int i=0 ; i<max_ ; i++){

        for( int j = l ; j < t; j++){
            arr[i][j] = ch[index];

         }
     }

    index =  ( biggest + 2 ) %3 ;
   // t += len[index][0]+len[index][1] - max_ ;
     for(int i=0 ; i<max_ ; i++){
        for( int j = t; j < max_; j++){
            arr[i][j] = ch[index];

         }
   }

   for(int i=0 ; i<max_ ; i++){
      for(int k=0 ; k<max_ ; k++){
         printf("%c",arr[i][k]);
      }
      printf("\n");
   }
      return 0;
   }

   if(len[ind[0]][0] == w-l || len[ind[0]][1] == w-l){
       int t = (len[ind[0]][0] + len[ind[0]][1] - (w-l)) ;
       if(len[ind[1]][0] == w-l || len[ind[1]][1] == w-l){
            int v = w - t ;
            if(v+t == max_){
                      printf("%d\n" , max_);
                      int i=0 ;
                     for(  ; i< l; i++){
                          for( int j=0; j< max_ ; j++){
                             arr[i][j] = ch[biggest];
                                           }
                                            }
                     int  k = i;
                     for(; i<max_ ; i++){
                         for(int j= 0 ; j<t ; j++){
                            arr[i][j] = ch[ind[0]];
                         }
                     }
                    for( k ; k <max_ ; k ++){
                         for(int j = t ; j< max_  ; j++){
                            arr[k][j] = ch[ind[1]];
                         }
                     }

                        for(int s=0 ; s<max_ ; s++){
                           for(int t=0 ; t<max_ ; t++){
                                   printf("%c",arr[s][t]);
                                  }
                                  printf("\n");
                        }

                    }
            else{
              printf("-1\n");
             return 0 ;
            }
       }else{
        printf("-1\n");
        return 0 ;
       }

   }else{
    printf("-1\n");
     return 0 ;
   }
   return 0 ;
}