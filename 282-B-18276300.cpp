#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define s 1000000

using namespace std;


int main(void) {

    int n ;
    long sum_G = 0L , sum_A = 0L;
    char chrs[s] ;
    scanf("%d",&n);
    for (int i=0 ; i<n ; i++){
        int ai , gi ;
        scanf("%d%d",&ai,&gi);
        if((sum_A+ai - sum_G) <= 500 ){
            sum_A += ai ;
            chrs[i] = 'A';
        }
        else{
            sum_G += gi ;
             chrs[i] = 'G';
        }
    }

   for(int i=0 ; i<n ; i++){
      printf("%c",chrs[i]);
   }
   cout << "\n" ;
	return 0;
}