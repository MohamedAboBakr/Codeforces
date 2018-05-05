#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int t[1005];
int s[1005];
int f[1005];
int meet[1005];
bool check(int i,int j,int tp1 , int tp2){
    int t1=t[i],t2=t[j];
    int s1=s[i],s2=s[j];
    int f1=f[i],f2=f[j];

    if(t1<t2){
         s1 += tp1*(t2-t1);
         t1=t2;
    }
    else if(t1>t2){
         s2 += tp2*(t1-t2);
         t2=t1;
    }
    if(tp1==1&&s1>f1 || tp1==-1&&s1<f1) return false ;
    if(tp2==1&&s2>f2 || tp2==-1&&s2<f2) return false ;
    if(tp1==tp2) return s1==s2 ;

    if(tp1==-1){
         swap(s1,s2);
         swap(f1,f2);
    }

    double met = 1.0*(max(s1,s2)-min(s1,s2))/2.0 ;
    if(s1+met<=f1&&s2-met>=f2&&s1+met==s2-met) return true ;
    return false ;
}
int main(){
 int n ; scanf("%d",&n);
 for(int i=0;i<n;i++) scanf("%d%d%d",&t[i],&s[i],&f[i]);
 for(int i=0;i<n;i++){
    int t1=(s[i]<f[i])?1:-1;
    for(int j=0;j<n;j++){
         if(i==j)continue;
         int t2=(s[j]<f[j])?1:-1;
         if(check(i,j,t1,t2)) meet[i]++;
    }
 }

 printf("%d",meet[0]);
 for(int i=1 ; i<n; i++){
    printf(" %d",meet[i]);
 }
 printf("\n");
 return 0 ;
}