#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
int a[505],b[505];
vector < pair < int,char > > ans ;

void solve(int fst , int last , int j , int mx){
      if(fst==last) return ;
      int index ;
      for(int i=last;i>=fst;i--){
          if(a[i]==mx){
              if(i==fst && a[i]!=a[i+1]) {
                  index=i;
                  break;
              }
              if(i==last && a[i]!=a[i-1]) {
                  index=i;
                  break;
              }
              if(i!=fst&&i!=last) {
                 if(a[i]!=a[i-1] || a[i]!=a[i+1]){
                    index=i;
                    break;
                 }
              }
          }
      }
      int f=index;
      index = index-fst+1+j;
    if(f==fst || f==last){
      for(int i=fst;i<f;i++){
          ans.push_back({index--,'L'});
      }
      for(int i=f+1;i<=last;i++){
          ans.push_back({index,'R'});
      }
    }

     else if(a[f]!=a[f-1]){
         for(int i=fst;i<f;i++){
          ans.push_back({index--,'L'});
          }
         for(int i=f+1;i<=last;i++){
          ans.push_back({index,'R'});
         }
      } else {

          ans.push_back({index,'R'});
          for(int i=fst;i<f;i++){
          ans.push_back({index--,'L'});
          }

          for(int i=f+2;i<=last;i++){
             ans.push_back({index,'R'});
          }


      }
}

int main(){
  int n,k ; scanf("%d",&n);
  for(int i=0;i<n;i++){
     scanf("%d",&a[i]);
  }
  scanf("%d",&k);
  for(int i=0;i<k;i++){
    scanf("%d",&b[i]);
  }

  int i=0,j=0,sum=0,last=0;
  int mn=1000005,mx=0;

  while(i<n){

        if(sum+a[i] < b[j]){
            sum = sum+a[i];
            mn = min(mn,a[i]);
            mx = max(mx,a[i]);
        }

        else if(sum+a[i] > b[j]){
            printf("NO\n");
            return 0 ;
        } else{

            mn = min(mn,a[i]);
            mx = max(mx,a[i]);
            if(mn == mx && last!=i){
                printf("NO\n");
                return 0 ;
            }
            solve(last,i,j,mx);
            sum = 0 ;
            last = i+1 ;
            mn=1000005;mx=0;
            j++;
            if(j==k)break;
        }

        i++ ;
  }
  if(i!=n-1){
               printf("NO\n");
                return 0 ;
  }
  printf("YES\n");
  for(int i=0;i<ans.size();i++){
      printf("%d %c\n",ans[i].first,ans[i].second);
  }
  return 0 ;
}