#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

map <ll,int> mp ;
map <ll,int>::reverse_iterator itt ;
int n ;


void solve(){
    itt = mp.rbegin();
    int flag=0;
    ll val = itt->first/2 ;
    while(val>0){
        if(mp.find(val)==mp.end()){
            mp.erase(itt->first);
            mp[val]=1 ;
            flag=1;
            break ;
        }
        val /= 2 ;
    }
    if(flag==1) solve();
}

int main(){
 scanf("%d",&n);
 ll num ;
 for(int i=0;i<n;i++){
    scanf("%lld",&num);
    mp[num] = 1 ;
 }

 solve();
 map<ll,int>::iterator it = mp.begin();
 printf("%lld",it->first); it++ ;
 for(; it != mp.end();it++){
     printf(" %lld",it->first);
 }

 printf("\n");
 return 0 ;
}