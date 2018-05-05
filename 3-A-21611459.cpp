#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int moves = 0 ;
vector <string> steps;
void solve(int x1 , int y1 , int x2 , int y2){
      if(x1==x2 && y1 == y2) return;
      if(x1 == x2){
           if(y1>y2) {
              steps.push_back("D"); moves++ ;
              solve(x1,y1-1,x2,y2);
           }else{
              steps.push_back("U"); moves++ ;
              solve(x1,y1+1,x2,y2);
           }
      }

      else if(y1 == y2){
            if(x1>x2) {
              steps.push_back("L");moves++ ;
              solve(x1-1,y1,x2,y2);
           }else{
              steps.push_back("R");moves++ ;
              solve(x1+1,y1,x2,y2);
           }
      }

      else if(x2 < x1){
            if(y1 > y2){
                steps.push_back("LD");moves++ ;
                solve(x1-1 , y1-1 , x2,y2);
            } else {
                steps.push_back("LU");moves++ ;
                solve(x1-1 , y1+1 , x2,y2);
            }
      } else if(x2 > x1){
            if(y1 > y2){
                steps.push_back("RD");moves++ ;
                solve(x1+1 , y1-1 , x2,y2);
            } else {
                steps.push_back("RU");moves++ ;
                solve(x1+1 , y1+1 , x2,y2);
            }
      }
}
int main(){
    string s1,s2 ; cin >> s1 >> s2 ;
    int src , dest ;
    src = ((s1[1]-'0')-1)*8 + (s1[0]-'a'+1);
    dest = ((s2[1]-'0')-1)*8 + (s2[0]-'a'+1);

    int x1,x2,y1,y2 ;
    x1 =src%8; if(x1==0) x1 = 8 ;
    y1 = (int)ceil(1.0*src/8);
    x2 =dest%8; if(x2==0) x2 = 8 ;
    y2 = (int)ceil(1.0*dest/8);
    solve(x1,y1 , x2,y2);
    printf("%d\n",moves);
    for(int i=0 ; i<moves ; i++){
         cout << steps[i] << "\n" ;
    }
  return 0 ;
}