#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>

/// C Header Files
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <ctime>
#include <cstring>


using namespace std;


/// Math Start
#define PI                    acos(-1.0)
#define Pi                    3.141592653589793
#define SQR(n)                ( n * n )
/// Math End


/// Pair Start
#define ff                    first
#define ss                    second
#define mp                    make_pair
/// Pair End


/// Array Start
#define SET(a)                memset( a, -1,    sizeof a )
#define CLR(a)                memset( a,  0,    sizeof a )
#define MEM(a,val)            memset( a,  val,  sizeof(a) )
/// Array End


/// Extra Start
#define nn                    '\n'
#define pb                    push_back
#define SS                    stringstream
#define ull                   unsigned long long
#define mod                   1000000007
#define INF                   2147483647
#define SIZE                  2005
#define _cin                  ios_base::sync_with_stdio(0);  cin.tie(0);
#define sz(a)                 int((a).size())
#define space                 " "
#define all(x)                (x).begin(), (x).end()
#define Ignore                cin.ignore()
#define StringToInt           if ( ! (istringstream(s) >> n) ) n = 0;
#define REP(i,n)              for(int i=0;i<(n);i++)
#define FOR(i,a,b)            for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)           for(int i=(a);i>=(b);i--)
#define fill1(a , z , v)      std::fill_n(a,z,v)
#define fill2(i,j,arr,v)      FOR(k,i,j) {  arr[k] = v ;}
#define print1(arr,n,st)      REP(i,n){ printf("%d%s",arr[i],st);}
#define print2(arr,n,st)      REP(i,n){ printf("%f%s",arr[i],st);}
#define print3(arr,n,st)      REP(i,n){ printf("%s%s",arr[i],st);}
#define read1(arr,n)          REP(i,n) sf1(arr[i]) ;
#define read4(arr,n)          REP(i,n) cin >> arr[i];
#define reline(st)            getline(cin , st , '\n');
#define read2(arr,n)          REP(i,n) reline(arr[i]);
#define read3(arr,n)          REP(i,n) cin >> arr[i];
#define read(st)              cin >> st ;
#define lnbreal()             getchar();

/// TypeDef Start
typedef  long long            ll;
typedef  long double             ld;
typedef  long                    l;
typedef  map<string,int>         msi;
typedef  map<int,int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<char,int>           mci;
typedef  map<int,string>	     mis;
typedef  pair<int,int> 	         pii;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef  vector<int> 	         vi;
typedef  vector<string> 	     vs;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  vector< pii >           vii;
/// TypeDef End


/// I/O Start
#define sf                    scanf
#define pf                    printf

#define sf1(a)                scanf("%d", &a)
#define sf2(a,b)              scanf("%d %d",&a, &b)
#define sf3(a,b,c)            scanf("%d %d %d", &a, &b, &c)
#define sf4(a,b,c, d)         scanf("%d %d %d %d", &a, &b, &c, &d)

#define sf1ll(a)              scanf("%I64d", &a)
#define sf2ll(a,b)            scanf("%I64d %I64d", &a, &b)
#define sf3ll(a,b,c)          scanf("%I64d %I64d %I64d", &a, &b, &c)
#define sf4ll(a,b,c, d)       scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &d)

#define READ                  freopen("input.txt", "r", stdin);
#define WRITE                 freopen("output.txt", "w", stdout);

/// I/O end

ll Factorial[SIZE] , F_Inv[SIZE];

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

ll  nCr_mod_m( int  n ,int r){

     return ((Factorial[n] * ( F_Inv[r] %mod))%mod * ( F_Inv[n-r] %mod))%mod ;
}


int main(void){

   Factorial[0] = 1L ; F_Inv[0] = 1L;
   FOR(i,1,SIZE){
        Factorial[i] = Factorial[i-1] * i % mod ;
        F_Inv[i] = Power(Factorial[i] , mod-2 );
   }
   int m , flag = 1 , r = 1 , n=0 , n2 = 0 ;
   ll ans = 0L;
   sf1(m);
   int arr[2000],flagg[2000] = {0};
   REP(i,m){
      sf1(arr[i]);
      if(arr[i] == -1) n++ ;
      else flagg[arr[i]-1] = 1 ;
   }

   REP(i,m){
       if(arr[i] == -1 && flagg[i] == 0) n2++;
   }

  // printf("%d \n" , n2);
   FORD(i,n-1,n-n2){
      ans = (((ans%mod) + (flag*(Factorial[i]*nCr_mod_m(n2,r))%mod + mod)%mod)%mod + mod)%mod;
    //  printf("%lld \n" , ans);
      flag *= -1 ;
      r++;
   }

   //ans = nCr_mod_m(2*n+2 , n+1) -1;
   cout << ((Factorial[n] - ans%mod)%mod+mod)%mod ;
   cout << "\n";
   return 0 ;
}