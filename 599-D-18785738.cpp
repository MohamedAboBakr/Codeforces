#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <math.h>


using namespace std;
typedef long long ll ;
ll arr[2000000][2] ;

int main(){


 ll x ; cin >> x ;
 if(x == 2){
    printf("2\n1 2\n2 1\n");
    return 0;
 }
 ll rt = (ll)ceil(cbrt(x));
 // printf("%lld\n" , rt);
 int c = 0 , res = 0;
 for(ll i=1 ; i<= (rt*2) ; i++){
    // printf("ooo\n" );
     ll val1 = (i*i + i)/2 ;
     ll val2 = (i*i*(i+1)/2);
     ll val3 = (i*(i+1)*(2*i+1)/6);
     ll val4 = x+val2-val3 ;

     if(val4 > 0 &&  val4%val1 == 0 && i <= val4/val1){
         arr[c][0] = i ; arr[c][1] = val4/val1 ;
         if(arr[c][0] == arr[c][1]) res ++ ;
         else res += 2 ;
         c++ ;
     }
 }

  printf("%d\n" , res);
  if(c != 0){
     for(int i=0 ; i<c ; i++){
        printf("%lld %lld\n",arr[i][0] , arr[i][1]);
     }
    // printf("88\n");
     if(arr[c-1][0] == arr[c-1][1]) c -= 1 ;
     for(int i= c-1 ; i>= 0 ; i--){
        printf("%lld %lld\n",arr[i][1] , arr[i][0]);
     }
  }

 return 0 ;
}