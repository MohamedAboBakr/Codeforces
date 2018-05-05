#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef double ld ;


int main()
{
    ll n,ln,v1,v2,k,groups;
    scanf("%lld%lld%lld%lld%lld",&n,&ln,&v1,&v2,&k);
    groups = (n+k-1)/k; // ceil_function
    ld l=0.0,r=(1.0*ln)/(1.0*v1);
    while((r-l)>= 1e-7){
        ld mid = (l+r)/2.0;
        ld t=0.0,x,y;
        for(int i=0;i<groups;i++){
              x = (1.0*ln-1.0*v1*mid)/(1.0*(v2-v1));
              t+=x ;
              if(i<groups-1){
                 y = 1.0*(v2-v1)*x/(1.0*(v1+v2));
                 t+=y;
              }
        }
        if(mid>=t) r=mid;
        else l=mid;
    }
    printf("%lf\n",l);
    return 0;
}