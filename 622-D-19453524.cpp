#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main(){
    int n ; cin >> n ;
    int a[2*n + 1];
    a[n*2] = n ;
    int i = 1 , j=n ;
    int val = 1;
    while(j >= i){
        if(i == j){
                a[i] = n ;
                break ;
        }
        a[i++] = val;
        a[j--] = val;
        val += 2 ;
    }

    i = n+1 ; j = 2*n-1 ;
    val = 2 ;
    while(j >= i){
        if(i == j){
                a[i] = n ;
                break ;
        }
        a[i++] = val;
        a[j--] = val;
        val += 2 ;
    }
    printf("%d" , a[1]);
    for(int i=2 ; i<= 2*n ; i++){
       printf(" %d" , a[i]);
    }
    printf("\n");
  return 0 ;
}