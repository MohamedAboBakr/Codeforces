#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;


int main()
{
    int n ; scanf("%d",&n);
    ll a[n] , b[n] ;
    for(int i=0 ; i<n ; i++){
         scanf("%lld",&a[i]);
    }
    b[n-1] = a[n-1] ;
    for(int i=n-2 ; i>=0 ; i--){
        b[i] = a[i]+a[i+1];
    }
    for(int i=0 ; i<n ;  i++){
        printf("%lld ",b[i]);
    }
    return 0;
}