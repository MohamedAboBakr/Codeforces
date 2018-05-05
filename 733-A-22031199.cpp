#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main(){
  string s ; cin >> s ;
  int len = s.length();
  int last=0,mxx=0;
  for(int i=0;i<len;i++){
      char c = s[i];
      int j=i+1;
      if(c=='A'|| c=='U'|| c=='E' || c== 'I' || c=='O' || c=='Y'){
          mxx = max(mxx,j-last) ;
          last = j ;
      }
  }

  mxx = max(len+1-last,mxx);
  printf("%d\n",mxx);
  return 0 ;
}