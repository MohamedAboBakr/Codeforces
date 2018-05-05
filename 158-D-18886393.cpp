#include <cstdio>
#include <vector>
#include <string>
#include <time.h>
#include <math.h>
#include<iostream>
using namespace std;
typedef long long ll ;

ll inv ;
int main()
{
 int n ; cin >> n ;
 vector<int> div ;
 int sqt = (int)sqrt(n);

 for(int i=2 ; i<= sqt ; i++){
      if(n%i == 0){
        int d1 = i , d2 = n/i ;
        if(d1 > 2) div.push_back(d2);
        if(d2 > 2) div.push_back(d1);
        }


 }

 int arr[n] , sum = 0;
 for(int i=0 ; i<n ; i++){
     cin >> arr[i]; sum += arr[i];
 }



int mx = sum;
int sz = div.size();


        for(int l=0 ; l<sz ; l++){

        for(int j=0 ; j<div[l] ; j++){
            int s = 0;
            for(int i = j ; i<n ; i+=div[l]){
            s += arr[i] ;
            }
            mx = max(mx ,s);
        }

    }



 printf("%d\n",mx);
 return 0;
}