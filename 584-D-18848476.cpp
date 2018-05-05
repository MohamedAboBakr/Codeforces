#include <cstdio>
#include <vector>
#include <string>
#include <time.h>
#include <math.h>
#include<iostream>
using namespace std;
bool isPrime(int x)
{

        if (x == 1 || (x % 2 == 0 && x != 2)) return false;
        for (int i = 3; i <= sqrt(x); i += 2)
            if (x % i == 0)
                return false;
        return true;
}

int get_prime(int p){
   for(int i = p ; i >= 3 ; i-=2){
      if(isPrime(i)){
          return i ;
      }
   }
   return 0 ;
}
int main()
{


 int n ; cin >> n ;
 if(n == 3) {
    printf("1\n3\n");
    return 0 ;
 }

  int p1 , p2 , p3 ;

  p1 = get_prime(n-2);
  if(n-p1 == 2){
    printf("2\n%d %d\n",p1 , 2);
    return 0 ;
  }
  if(n-p1 == 4){
    printf("3\n%d 2 2\n",p1);
    return 0 ;
  }

  for(int i= n-p1-3 ; i>=1 ; i-= 2){
     if(isPrime(i) && isPrime(n-p1-i)){
        p2 = i  ; p3 = n-p1-i ; break ;
     }
  }

  printf("3\n%d %d %d\n",p1,p2,p3);
 return 0;
}