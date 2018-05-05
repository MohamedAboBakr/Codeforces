#include <cstdio>
#include <vector>
#include <string>
#include <time.h>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;


int main()
{

 vector<int> perm ;
 perm.push_back(1689);
 perm.push_back(1698);
 perm.push_back(1896);
 perm.push_back(1869);
 perm.push_back(1968);
 perm.push_back(1986);
 perm.push_back(6198);

 int n  , f1 = 0 , f6 = 0 , f8 = 0 , f9 = 0 ;
 int rem = 0 ;
 string zero = "" ;
 string digits = "" ;
 char c = getchar();
 while(c != '\n'){
    
    if(c == '0') zero += '0';
    else if(c == '1' && f1 == 0) f1 = 1 ;
    else if(c == '6' && f6 == 0) f6 = 1 ;
    else if(c == '8' && f8 == 0) f8 = 1 ;
    else if(c == '9' && f9 == 0) f9 = 1 ;
    else{
        digits += c ;
        rem *= 10 ;
        rem = (rem + (c-'0'))%7 ;
       // printf("%d\n",rem);

    }
    c = getchar();
 }

 cout << digits ;
 for(int i=0 ; i<7 ; i++){
    if((rem*10000 + perm[i]) %7 == 0){
        cout << perm[i] ;
        cout << zero ;
        cout << "\n" ;
        return 0 ;
    }
 }
 return 0;
}