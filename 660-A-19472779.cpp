#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

vector<int> num ;
int main(){
   int n ; scanf("%d",&n);
   int a[n] ;
   scanf("%d",&a[0]) ;
   if(n == 1){
       printf("0\n%d\n" , a[0]);
       return 0 ;
   }
   num.push_back(a[0]);
   int k = 0 ;
   for(int i=1 ; i<n ; i++){
       scanf("%d",&a[i]) ;
       if(__gcd(a[i] , a[i-1]) == 1){
          num.push_back(a[i]);
       } else {
          num.push_back(1);
          num.push_back(a[i]);
          k++ ;

   }
   }
   printf("%d\n",k);
   printf("%d",num[0]);
   for(int i=1 ; i<num.size() ; i++){
     printf(" %d",num[i]);
   }

   printf("\n");
 }