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
#define SIZE                  200005
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

int main(void){

   int n ;
   sf1(n);
   int pow_26[5] , pow_10[7];
   pow_26[0] = 1 ; pow_10[0] = 1;
   for(int i=1 ; i<5 ; i++){
      pow_26[i] = pow_26[i-1] * 26;
      pow_10[i] = pow_10[i-1] * 10;
   }
   pow_10[5] = 100000 ;
   pow_10[6] = 1000000;
   string str ;
   REP(u,n){
      cin >> str ;
      int len = str.length();
      int type = 1 , row = 0 , t = 0;
      int i ;
      for(i=len-1 ; i>=0 ; i--){
          char c =   str.at(i) ;
       if(c >= 'A' && c <= 'Z'){
          if( c == 'C'){
             if(i > 0 && (str.at(i-1) >= '0' && str.at(i-1) <= '9')){
                 type = 2 ;
            }
        }
        break ;
       }

       row += (c-'0')*pow_10[t];
       t++ ;
      }

      int col = 0 ;
      if(type == 1){
          int t = 0 ;
          for(int j = i ; j>= 0 ; j--,t++){
             char c = str.at(j);
             col += (c-'A'+1)*pow_26[t];
          }

          printf("R%dC%d\n",row,col);

      }

      else{
        int t = 0 , cl = 0 , l = 0 ;
        for(int j = i-1 ; j>0 ; j-- , t++){
            cl += (str.at(j)-'0')*pow_10[t];
        }

      //  printf("%d  %d \n" , row , cl);
        string col = "";

        while(row != 0){
            char c ;
            int rem = row%26 ;
            if( rem == 0 ){
                c = 'Z' ;
                row -- ;
            }
            else c = (char)(rem-1+'A') ;
            col += c;
            l ++ ;
            row /= 26 ;
        }

        for(int j=l-1 ; j>= 0 ;j--){
            cout << col.at(j);
        }
        printf("%d\n" , cl);
      }
   }
   return 0 ;
}