#include <cstdio>
#include <vector>
#include <string.h>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main(){
   int h1 , h2 , a,b ;
   cin >> h1 >> h2 >> a >> b ;
	if (h1 + 8 * a >= h2)
		puts("0");
	else if (a > b) {
		int num = h2 - h1 - 8 * a, den = 12 * (a - b);
		cout << (num + den - 1) / den << endl;
	} else
		puts("-1");

   return 0 ;
}