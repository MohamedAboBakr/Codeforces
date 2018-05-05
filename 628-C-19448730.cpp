#include <cstdio>
#include <vector>
#include <string.h>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;


char str[100001];
int main(){
  int n ,k ;
  scanf("%d%d",&n,&k);
  getchar();
  gets(str);
  int len = strlen(str);
  char res[n];
  for(int i =0 ; i<len ; i++){
     if(k ==0) res[i] = str[i] ;
     else{
        if('z'-str[i] >= str[i]-'a'){
             int d = 'z'-str[i] ;
             if(k >= d) {
                res[i] = 'z' ;
                k -= d ;
             }else{
                res[i] = str[i]+k;
                k = 0 ;
             }
        }else{
            int d = str[i] - 'a' ;
             if(k >= d) {
                res[i] = 'a' ;
                k -= d ;
             }else{
                res[i] = str[i]-k;
                k = 0 ;
             }
        }
     }
  }
  res[n] = '\0';
  if(k != 0){
    printf("-1\n");
    return 0 ;
  }
  printf("%s\n" , res);
  return 0 ;
}