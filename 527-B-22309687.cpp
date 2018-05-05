#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

map < pair <char , char> , int > mp;

int main(){
   int n ,diff = 0; scanf("%d",&n);
   string a,b ;
   cin >> a >> b  ;
   int arr1[27],arr2[27];
   memset(arr1,0,sizeof(arr1));
   memset(arr2,0,sizeof(arr2));

   for(int i=0;i<n ;i++){
      if(a[i]==b[i]) continue ;
      diff++;
      arr1[a[i]-'a'] = i+1;
      arr2[b[i]-'a'] = i+1;
      mp[{a[i],b[i]}] = i+1 ;
    }

   if(diff<2){
       printf("%d\n-1 -1\n",diff);
       return 0 ;
   }

   map < pair <char , char> , int >::iterator it = mp.begin();
   for(; it != mp.end();it++){
        char c1 = it->first.first , c2 = it->first.second ;
        if(mp.find({c2,c1})!=mp.end()){
             printf("%d\n",diff-2);
             printf("%d %d\n",mp[{c1,c2}],mp[{c2,c1}]);
             return 0 ;
        }
   }

   for(int i=0;i<27;i++){
     if(arr1[i]>0 && arr2[i]>0){
          printf("%d\n",diff-1);
          printf("%d %d\n",arr1[i],arr2[i]);
          return 0 ;
     }
   }

   printf("%d\n-1 -1\n",diff);
   return 0 ;
}