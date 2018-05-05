#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#define s 200001

using namespace std;

int flag[s] = {0};
int main(void) {



    vector<int> v ;
    int n  , counter = 1 , choose;
    long sum =  0L , m;
    scanf("%d%ld",&n , &m);

    for (int i= 1 ; i<=n ; i++){
        scanf("%d",&choose);
        if(choose < s) flag[choose] = 1 ;
    }

    for(int i = 1 ; (i<=s) && (sum+i <= m); i++){
        if(flag[i] == 0){
                  v.push_back(i);
                  sum += i ;
        }

    }

   int si = v.size() ;
   printf("%d\n" , si);
   for(int i=0 ; i<si ; i++){
    printf("%d%s" , v[i] , (i == si-1) ? "\n" : " ");
   }
	return 0;
}