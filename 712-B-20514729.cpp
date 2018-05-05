#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;


int main()
{
    string s ;
    cin >> s;
    int len = s.length();
    if(len&1){
        printf("-1\n");
        return 0 ;
    }
    int l=0 , r=0 , u=0 ,d=0 ;
    for(int i=0 ; i<len ; i++){
         char c = s[i] ;
         if(c == 'L') l++ ;
         else if(c =='R') r++ ;
         else if(c == 'U') u++ ;
         else d++;
    }


    int mn1 = max(u,d)-min(u,d);
    int mn2 = max(r,l)-min(r,l);
    int mn = (min(mn1,mn2)+max(mn1,mn2))/2 ;
    printf("%d\n",mn);
    return 0;
}