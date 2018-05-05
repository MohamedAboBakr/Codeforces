#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define mod 1000000007

ll nCr[200005];
ll pi[1000001] ;
bool flag[1000001];
int arr[200005];
ll ans = 0 ;
map < int , int > multiples ;
map < int , vector < int > > factors ;

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


void sieve_euler(){
   for(int i=1 ; i<= 1000000 ; i++){
         pi[i] = i ;
    }

    for( int i=1 ; i<= 1000000 ; i++ ){
             for( int j=i ; j <= 1000000 ; j+=i ){
                 if(j!=i) pi[j] -= pi[i];
                 if(flag[j] == true) factors[j].push_back(i);
             }
    }

}

void combinations(int k){
   nCr[k] = 1 ;
   for(int i=k+1 ; i<= 200000 ; i++){
           nCr[i] = ((nCr[i-1]*i)%mod*Power(i-k,mod-2))%mod  ;
   }
}

void factorize(int a , int k){
       vector<int> v = factors[a] ;
       for(int i=0 ; i<v.size() ; i++){
                 multiples[v[i]]++ ;
                 ans = (ans + (pi[v[i]]*(nCr[multiples[v[i]]]-nCr[multiples[v[i]]-1]+mod)%mod)%mod)%mod ;
       }

}


int main(){

  int n,k,q,a; scanf("%d%d%d",&n,&k,&q);
  combinations(k);
  for(int i=0 ; i<n+q ; i++){
        scanf("%d",&arr[i]);
        flag[arr[i]] = true;
  }
  sieve_euler();
  for(int i=0 ; i<n ; i++){
      factorize(arr[i],k);
  }
 for(int i=n ; i<n+q; i++){
      factorize(arr[i],k);
      printf("%lld\n",ans);
  }
  return 0 ;
}