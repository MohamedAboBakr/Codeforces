#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n,ai;
    long long k;
    scanf("%d%lld",&n,&k);
    vector<int> a;
    for(int i=0;i<n;i++){
       scanf("%d",&ai);
       a.push_back(ai);
    }
    if(k>=n){
       int mx=a[0];
       for(int i=0;i<n;i++){
         mx=max(mx,a[i]);
       }
       printf("%d\n",mx);
       return 0;
    }
    int wn=0,i=0,t=0;
    int lastt=-1;
    for(int i=0;i<n;i++){
       wn=0;
       if(i>0&&a[i]>lastt) wn++;
       for(int j=i+1,t=0;j<a.size()&&t<k;j++,t++){
           if(a[i]>a[j]){
               wn++;
               a.push_back(a[j]);
               if(wn>=k){
                 printf("%d\n",a[i]);
                 return 0;
               }
           }
           else {
           a.push_back(a[i]);
           lastt=a[i];
           i=j-1;
           break;
           }
       }
    }


    printf("%d\n",a[n-1]);
    return 0;
}