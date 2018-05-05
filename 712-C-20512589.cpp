#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;


int main()
{
    int x,y ; scanf("%d%d",&x,&y);
    vector<int> v ;

    v.push_back(y); v.push_back(y);
    v.push_back(y);

    sort(v.begin() , v.begin()+3);
    int mn = 0 ;
    while(!(v[0]==x && v[1]==x && v[2]==x)){

       v[0] = v[1]+v[2]-1 ;
       if(v[0] > x) v[0] = x ;
       mn++ ;
       sort(v.begin() , v.begin()+3);
    }
    printf("%d\n",mn);
    return 0;
}