#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#define s 40000
#define e 2.71828
using namespace std;


int main(void) {

    int n  , k , c = 1;
    scanf("%d%d",&n , &k);
    int arr[n][4];

    for(int i=0 ; i<n ; i++){
        arr[i][0] = c* k ;
        c++ ;
        arr[i][1] = c* k ;
        c++ ;
        arr[i][2] = c* k ;
        c += 2 ;
        arr[i][3] = c* k ;
        c += 2 ;
    }

    printf("%d\n",arr[n-1][3]);
    for (int i= 0 ; i<n ; i++){
        printf("%d %d %d %d\n",arr[i][0] , arr[i][1]  , arr[i][2]  ,arr[i][3] );
    }


	return 0;
}