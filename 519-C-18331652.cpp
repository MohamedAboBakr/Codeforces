#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#define s 40000
#define e 2.71828
using namespace std;

int get_team(int a , int b){
    if(a == 0 || b == 0) return 0 ;

        if(a*2 < b) {
        return a ;
    }

    int d = b/2;
    if((a - d) > 1 && b%2 == 1) d += 1 ;
    return d ;
}
int main(void) {

    int n  , m , min , mx , ans = 0;
    scanf("%d%d",&n , &m);


    min = (n < m) ? n : m ;
    mx = (n > m) ? n : m ;

    int diff = mx - min ;
    if(min >= diff){
        ans += diff ;
        min -= diff ;
        mx -= (2*diff);
    }


    int sol1 = (min/3)*2 ;
    int num = (sol1/2)*3 ;
    int rest1 = min-num ;
    int rest2 = mx-num ;

    sol1 += get_team(rest1 , rest2);
   int sol2 = get_team(min , mx);

    printf("%d\n",max(sol1 , sol2) + ans);
	return 0;
}