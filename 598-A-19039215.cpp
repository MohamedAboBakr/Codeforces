#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

ll pow_2[31];
int main()
{
    pow_2[0] = 1 ;
    for(int i=1;i<31 ; i++){
        pow_2[i] = pow_2[i-1]*2;
    }
    int t ; cin >> t ;
    ll n , ans;
    while(t != 0){
         ans = 0L;
         cin >> n ;
         ans += (n*(n+1)/2) ;
         ll lg = (ll)log2(1.0*n);
        // printf("%lld\n",lg);
         ans -=  2*((ll)pow(2,lg+1)-1);
         printf("%lld\n",ans);
    t-- ;
    }
    return 0;
}