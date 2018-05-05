#include <cstdio>
#include <vector>
#include <string>
#include <time.h>
#include <math.h>
#include<iostream>
using namespace std;
bool isPrime(int& x)
{

        if (x == 1 || (x % 2 == 0 && x != 2)) return false;
        for (int i = 3; i <= sqrt(x); i += 2)
            if (x % i == 0)
                return false;
        return true;
}


int main()
{


 int n ; cin >> n ;
 if(n == 3) {
    printf("1\n3\n");
    return 0 ;
 }
  else if(n == 5){
    printf("2\n2 3\n");
    return 0 ;
  }
  else if(n == 7){
    printf("2\n2 5\n");
    return 0 ;
  }

  else{
    printf("3\n3 ");
    n = n-3 ;
    int n2 = n ;
    int p1 , p2 ;
    for(int i=0; i<=n/2; i++)
 {
       if(isPrime(i))
       {
                int f=0 ;
                for(int j = n2-1; j >= n/2; j-=2){
                       if(isPrime(j) && i+j == n){
                              p1 = i ; p2 = j ; f = 1 ;break ;
                         }
                       else if(i+j < n){
                                   n2 = j+1;
                                   break;
                                           }
                }
                if(f == 1) break;
      }
 }
    printf("%d %d\n",p1 , p2);
  }

 return 0;
}