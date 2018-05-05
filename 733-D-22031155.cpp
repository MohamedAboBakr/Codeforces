#include<bits/stdc++.h>
using namespace std;
typedef long double ll ;


map < pair< int  , int > , pair< int  , int > >  mp ;


int main(){
 int n ; scanf("%d",&n);
 int x,y,z,vol=0,num=0,ind1,ind2;

 for(int i=1 ; i<= n ; i++){
    cin >> x >> y >> z ;
    if(x>y) swap(x,y);
    if(x>z) swap(x,z);
    if(y>z) swap(y,z);
    if(mp.find({y,z})!=mp.end()){
          int curr = min(y,mp[{y,z}].first+x);
          if(curr > vol){
              vol = curr ;
              num = 2 ;
              ind1 = i ;
              ind2 = mp[{y,z}].second ;
          }

          if(mp[{y,z}].first<x) mp[{y,z}] = {x,i} ;
    }else{

       if(x > vol){
           vol = x ;
           num=1;
           ind1=i ;
       }
       mp[{y,z}] = {x,i} ;
    }
 }

  printf("%d\n",num);
 if(num == 1) printf("%d\n",ind1);
 else printf("%d %d\n",ind1 ,ind2);
  return 0 ;
}