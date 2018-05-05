#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;


int main(){ 
    int n; scanf("%d",&n);
    int layers=0;
    int end = (n%2)?1:0;
    for(int i=n;i>=end; i-=2){
      layers += i;
    }
    printf("%d\n",layers);
    return 0;
}