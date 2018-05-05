#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define s 1000000
#define s2 500000
using namespace std;

int flag[s2][2] = {0} ;
int index[s2] = {0};
int main(void) {

    int n , counter1 = 0 , counter2 = 0 , c=0;
    scanf("%d",&n);
    printf("%d\n",n);

    for(int i=0 ; i<n ; i++){
        int x ;
        scanf("%d",&x);
        int val = s+1-x ;
        int row = min(x,val)-1;
        int col = (x > val)? 1 : 0;
       // printf("%d %d\n %d %d\n" , x , val, row , col);
        flag[row][col] = 1 ;
    }

    for(int i=0 ; i < s2 ; i++){
         int sum = flag[i][0]+flag[i][1] ;
         if(sum == 0){
            index[counter1] = i ;
            counter1 ++ ;
         }
         else if(sum == 2){
            counter2++;
         }else{
             if(flag[i][0] == 1) printf("%d",s-i);
             else printf("%d",i+1);
             printf("%s",(c == n-1)? "\n" : " ");
             c++;
         }
    }

    for(int i=0 ; i<counter1 &&  i<counter2 ; i++ , c++){
        printf("%d %d%s",index[i]+1,s-index[i],(c == n-1)? "\n" : " ");
    }
	return 0;
}