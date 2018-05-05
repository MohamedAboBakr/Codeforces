#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main(){
   ll mx = 1e18;
   ll x,y,l,r,p1,p2;
   vector<ll> x_powers , y_powers , unlucky;
   bool f1 = false  , f2 = false  ;
   scanf("%lld%lld%lld%lld",&x,&y,&l,&r);
   p1 = log(mx)/log(x);
   p2 = log(mx)/log(y);
   int i=0;
   ll xx = 1 ;
   for( ; i<p1 ; i++){
      x_powers.push_back(xx);
      xx *= x;
   }
   x_powers.push_back(xx);

   i = 0 ;
   ll yy = 1 ;
   for( ; i<p2 ; i++){
      y_powers.push_back(yy);
      yy *= y;
   }
   y_powers.push_back(yy);

   for(int i=0 ; i < x_powers.size() ; i++){
          for(int j=0 ; j < y_powers.size(); j++){
               ll check = x_powers[i]+y_powers[j] ;
               // printf("%lld\n",check);
               if(check >= l && check <= r) unlucky.push_back(check);
               if(l == check) f1 = true ;
               if(r == check) f2 = true ;
          }
   }

   sort(unlucky.begin() , unlucky.end());
   ll GoldenAge = 0 ;

   if(unlucky.size() == 0){
       printf("%lld\n",r-l+1);
       return 0 ;
   }

   for(int i=1; i<unlucky.size();i++){
       GoldenAge = max(GoldenAge , unlucky[i]-unlucky[i-1]-1);
   }

   if(f1) GoldenAge = max(GoldenAge , unlucky[0]-l-1);
   else   GoldenAge = max(GoldenAge , unlucky[0]-l);

   if(f2) GoldenAge = max(GoldenAge , r-unlucky[unlucky.size()-1]-1);
   else   GoldenAge = max(GoldenAge , r-unlucky[unlucky.size()-1]);

   printf("%lld\n",GoldenAge);
  return 0 ;
}