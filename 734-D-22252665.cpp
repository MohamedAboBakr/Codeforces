#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

ll x0,y_;
struct shape{

   char type ;
   ll x = 1e10 ,  y = 1e10;


};

struct shape arr[8];

bool vert(ll x){
     return x==x0 ;
}

bool horz(ll y){
     return y==y_ ;
}

bool diag(ll x, ll y){
    return abs(x-x0)==abs(y-y_);
}

int solve(char c , ll x ,  ll y){
       if(x==x0){
             if(y>y_&&y<arr[0].y) {
                    arr[0].y = y ;
                    arr[0].type = c ;
             }
             else if(y<y_&&y>arr[4].y){
                arr[4].type = c ;
                arr[4].y = y ;
             }
       }

       else if(y==y_){
             if(x>x0&&x<arr[6].x) {
                    arr[6].x = x ;
                    arr[6].type = c ;
             }
             else if(x<x0&&x>arr[2].x) {
                    arr[2].x = x ;
                    arr[2].type = c ;
             }
       }
       else {

           if(diag(x,y)){
                // printf("yes");
                 if(x>x0&&y>y_){
                       if(x<arr[7].x){
                          arr[7].x = x ;
                          arr[7].type = c ;
                       }
                 }else if(x>x0&&y<y_){
                       if(x<arr[5].x){
                          arr[5].x = x ;
                          arr[5].type = c ;
                       }
                 }
                 else if(x<x0&&y>y_){
                       if(x>arr[1].x){
                          arr[1].x = x ;
                          arr[1].type = c ;
                       }
                 }

                 else if(x<x0&&y<y_){
                       if(x>arr[3].x){
                          arr[3].x = x ;
                          arr[3].type = c ;
                       }
                 }
           }
       }
}

void initialize(){

   struct  shape sh ;
   sh.type = 'Z';
   sh.x = x0 ;
   sh.y = 1e10 ;
   arr[0] = sh ;
   sh.y = -1e10 ;
   arr[4] = sh ;
   sh.x = 1e10 ;
   arr[6] = sh ;
   arr[7] = sh ;
   arr[5] = sh ;
   sh.x = -1e10 ;
   arr[2] = sh ;
   arr[1] = sh ;
   arr[3] = sh ;

}
int main(){
  int n ; scanf("%d",&n);
  ll x,y;
  char c ;
  scanf("%lld%lld",&x0,&y_);getchar();
  initialize();
  for(int i=0;i<n;i++){
     scanf("%c",&c);getchar();
     scanf("%lld%lld",&x,&y);getchar();
     solve(c,x,y);
  }
  for(int i=0;i<8;i++){
    //   printf("%d  %c\n",i,arr[i].type);
      if(i%2==0){

          if(arr[i].type == 'Q' || arr[i].type == 'R') {
              printf("YES\n");
              return 0;
          }
      }else{
          if(arr[i].type == 'Q' || arr[i].type == 'B') {
              printf("YES\n");
              return 0;
          }
      }
  }
  printf("NO\n");
  return 0 ;
}