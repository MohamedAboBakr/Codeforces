#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main(){
 string s ; cin >> s ;
 int t ; cin >> t;
 int arr[t][3];
 for(int i=0 ; i<t ; i++){
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2] ;
    arr[i][0]-- ;
    arr[i][1]-- ;
    arr[i][2] %= (arr[i][1]-arr[i][0] + 1) ;
 }


 int len = s.length() , curr_index;
 char chrs[10000] ;
 for(int i=0 ; i<len ; i++){
    char c = s[i];
    curr_index = i ;
    for(int j=0 ; j<t ; j++){
        if(arr[j][0] <= curr_index && arr[j][1] >= curr_index){
            curr_index = (curr_index+arr[j][2]);
            if(curr_index > arr[j][1]){
                curr_index = arr[j][0] + curr_index - arr[j][1] -1;
            }
    }
    }
  // printf("%d %d\n" , i , curr_index);
   chrs[curr_index] = c ;
 }
 for(int i=0 ; i<len ; i++){
    printf("%c",chrs[i]);
 }
 printf("\n");
 return 0 ;
}