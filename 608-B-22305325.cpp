#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main(){
    string a,b ;
    cin >> a >> b ;
    int l1=a.length(),l2=b.length();
    int ones[l2+5];
    ones[0]=0;
    for(int i=0;i<l2;i++){
        if(b[i]=='1'){
             ones[i+1] = ones[i]+1 ;
        } else ones[i+1]=ones[i];
    }

    ll sum=0,k;
    for(int i=0;i<l1;i++){

         if(a[i]=='0'){
            sum += ones[l2-(l1-1-i)]-ones[i];
         }else{
             k = l2-l1+1 ;
             sum += k-(ones[l2-(l1-1-i)]-ones[i]);
         }
    }

    printf("%lld\n",sum);
}