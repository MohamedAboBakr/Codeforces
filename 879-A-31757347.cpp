#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n,s,d;
    scanf("%d",&n);
    vector<int> si,di;
    for(int i=0;i<n;i++){
       scanf("%d%d",&s,&d);
       si.push_back(s);
       di.push_back(d);
    }

    int nextt=si[0];
    for(int i=1;i<n;i++){
       int j;
       for(j=si[i];j<=nextt;j+=di[i]){
       }
       nextt=j;
    }
    printf("%d\n",nextt);
    return 0;
}