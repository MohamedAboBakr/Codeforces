#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
int n,k ;
int change  ;
char color[500005];
char s1[500005];
char s2[500005];

void solve(){
     if(k==2){
          int ch1=0,ch2=0 ;
          for(int i=0;i<n;i++){
              if(color[i]!=s1[i]) ch1++;
              if(color[i]!=s2[i]) ch2++;
          }
          printf("%d\n",min(ch1,ch2));
          if(ch1<ch2){
              for(int i=0;i<n;i++){
                  printf("%c",s1[i]);
              }
          }else{
              for(int i=0;i<n;i++){
                  printf("%c",s2[i]);
              }
          }
          printf("\n");
          return ;
     }

     for(int i=1;i<n;i++){
            if(color[i]==color[i-1]){
                  char c ;
                  for(c = 'A' ; c==color[i-1]||c==color[i+1] ; c++){}
                  color[i] = c ;
                  change++ ;
            }
     }

     printf("%d\n",change);
     for(int i=0;i<n;i++){
                  printf("%c",color[i]);
     }
     printf("\n");
}




int main(){
  scanf("%d%d",&n,&k); getchar();
  scanf("%s",color);
  int curr = 0 ;
  change = 0 ;
  int f=1 ;
  for(int i=0;i<n;i++){
      if(f==1){
        f *= -1;
        s1[i]='A';
        s2[i]='B';
      }else{
         f*=-1;
         s1[i]='B';
         s2[i]='A';
      }
  }
  solve();
  return 0 ;
 }