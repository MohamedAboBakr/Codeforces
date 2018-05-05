#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define s 1000000

using namespace std;


int main(void) {

    int n , min = 0 , res;
    long sum =  0 ;
    scanf("%d",&n);
    int arr[n] ;
    for (int i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
        if(arr[i] < min) min = arr[i];
    }

    min *= -1 ;
    for (int i=0 ; i<n ; i++){
        arr[i] += min ;
        sum += arr[i];
    }

   if(sum % n == 0) res = n ;
   else res = n-1 ;


   printf("%d\n",res);
	return 0;
}