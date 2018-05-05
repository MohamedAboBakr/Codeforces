#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
int row[2001][2001] ;
int col[2001][2001] ;
int main(){
  int n,m,w=0; scanf("%d%d",&n,&m); getchar();
  int mnx=2005,mny=2005 , mxx=-1 ,mxy=-1;
  char win[n+1][m+1] ;
  for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){
        scanf("%c",&win[i][j]);
        row[i][j]=row[i][j-1];
        col[i][j]=col[i-1][j];
        if(win[i][j]=='w'){
                w++;
                mnx = min(mnx,i);
                mxx = max(mxx,i);
                mny = min(mny,j);
                mxy = max(mxy,j);
                row[i][j]++; col[i][j]++ ;
        }
  }getchar();}

 /* for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         printf("%d  ",row[i][j]);
      }
      printf("\n");
  }*/
  if(w==1){
      for(int v=1;v<=n;v++){
         for(int u=1;u<=m;u++){
             printf("%c",win[v][u]);
         }
         printf("\n");
      }
      return 0;
  }

  int d1 = mxy-mny , d2 = mxx-mnx;
  if(d2>=d1){

      int flag=0;
      int i=1,j=d2+1;
      for(;j<=m;j++,i++){
           if(row[mnx][j]-row[mnx][i-1]+row[mxx][j]-row[mxx][i-1]+col[mxx-1][j]-col[mnx][j]+col[mxx-1][i]-col[mnx][i] == w){
              flag=1;
              break;
           }
      }
      if(flag==0){
         printf("-1\n"); return 0 ;
      }
      for(int v=1;v<=n;v++){
         for(int u=1;u<=m;u++){
             if((v==mnx||v==mxx)&&u>=i&&u<=j&&win[v][u]=='.')win[v][u]='+';
             else if((u==i||u==j)&&v>=mnx&&v<=mxx&&win[v][u]=='.') win[v][u]='+';
             printf("%c",win[v][u]);
         }
         printf("\n");
      }
      return 0 ;
  }

      int flag=0;
      int i=d1+1,j=1;
      for(;i<=n;j++,i++){
           if(row[j][mxy-1]-row[j][mny]+row[i][mxy-1]-row[i][mny]+col[i][mny]-col[j-1][mny]+col[i][mxy]-col[j-1][mxy] == w){
              flag=1;
              break;
           }
      }
      if(flag==0){
         printf("-1\n"); return 0 ;
      }
      for(int v=1;v<=n;v++){
         for(int u=1;u<=m;u++){
             if((v==i||v==j)&&u>=mny&&u<=mxy&&win[v][u]=='.')win[v][u]='+';
             else if((u==mny||u==mxy)&&v>=j&&v<=i&&win[v][u]=='.') win[v][u]='+';
             printf("%c",win[v][u]);
         }
         printf("\n");
      }
  return 0;

}