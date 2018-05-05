#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#define s 40000
#define e 2.71828
using namespace std;

int main(void) {

    int n  , m , ans = 0;
    scanf("%d%d",&n , &m);

   while(1){
       if((n == 1 && m == 1) || n == 0 || m == 0 ) break ;
       if(n > m){
          ans ++ ;
          n -= 2 ;
          m -= 1 ;
       }

       else if(n < m){
          ans ++ ;
          n -= 1 ;
          m -= 2 ;
       }

       else{
         // int t = (n/3)*2 ;
          ans += (n/3)*2 ;
          n = m = (n%3) ;
          if(n == 2){
                ans += 1;
               break ;
       }
       }
   }

   printf("%d\n", ans);
	return 0;
}