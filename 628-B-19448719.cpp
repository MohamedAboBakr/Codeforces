#include <cstdio>
#include <vector>
#include <string.h>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

 char str[300001];
int main(){
    ll ans =  0;
    gets(str);
    int len = strlen(str);
    if(len == 1){
        if((str[0]-'0')%4 == 0) ans = 1 ;
        else ans = 0 ;
        printf("%lld\n" , ans);
        return 0 ;
    }
    if((str[0]-'0')%4 == 0) ans++;
    for(int i=1 ; i<len ; i++){
        if((str[i]-'0') %4 == 0) ans ++ ;
        int curr = (str[i-1]-'0')*10 + (str[i]-'0') ;
        if(curr % 4 == 0) ans += i ;
    }
    printf("%lld\n" , ans);
 return 0;
}