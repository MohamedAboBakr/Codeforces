#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

char arr[300005];
int q,n,m,ans=0;
char c ;
void solve(){
   int sum=0;
   for(int i=0;i<n;i++){
      if(arr[i]=='.'){
         sum++;
         continue ;
      }else{
         if(sum!=0) ans += (sum-1);
         sum=0;
      }
   }
   if(sum!=0) ans += (sum-1);
}

int check(int index){
     if(index<0 || index >= n) return 0 ;
     if(arr[index] == '.') return 1 ;
     return 0 ;
}
void add(int index , char c ){
     if(arr[index] == '.') return ;
     int sum = check(index+1)+check(index-1);
     ans += sum ;
     arr[index] = '.';
}

void delete_(int index , char c ){
      if(arr[index] != '.') return ;
      int sum = check(index+1)+check(index-1);
      ans -= sum ;
      arr[index] = c;
}
int main(){
  scanf("%d%d",&n,&m); getchar();
  scanf("%s",arr);
  solve();
  for(int i=0 ; i<m;i++){
     scanf("%d %c",&q,&c);
     if(c == '.') add(q-1 , c);
     else delete_(q-1,c);
     printf("%d\n",ans);
  }
  return 0 ;
}