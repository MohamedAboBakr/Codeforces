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
    int x1,x2,y1,y2 ;
    cin >> x1 >> y1 >> x2 >> y2 ;
    printf("%d\n" , max(abs(x1-x2) , abs(y1-y2)));
   return 0 ;
}