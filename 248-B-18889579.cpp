#include <cstdio>
#include <vector>
#include <string>
#include <time.h>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

ll mod = 210 ;

ll  Power(ll base , ll times){
        if(base == 0) return 0L;
        if(times == 1) return base ;
        ll ans = 1 ;
        ll  base_binary = base ;
        while(times > 0){
            if(times % 2 == 1) ans = ((ans%mod) * (base_binary%mod))%mod ;
            base_binary = (base_binary % mod)*(base_binary % mod)%mod;
            times /= 2 ;
        }
        return ans%mod ;
}

int main()
{
 int n ;
 cin >> n ;
 if(n < 3){
    printf("-1\n");
    return 0 ;
 }
else if(n == 3){
 printf("210\n");
 return 0 ;
}

int rm = (5*Power(10 , n-3))%mod ;
int r = rm , len = 0;
 while(r != 0){
    len++;
    r /= 10 ;
}
len++;
printf("1");
for(int i=0 ; i< n-len ; i++){
    printf("0");
 }

printf("%d\n",rm);
 return 0;
}