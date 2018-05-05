#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long double ld ;
#define PI 3.14159265359

void merge(ld arr[][2], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    ld L[n1][2], R[n2][2];


    for (i = 0; i < n1; i++){
        L[i][0] = arr[l + i][0];
        L[i][1] = arr[l + i][1];
    }
    for (j = 0; j < n2; j++){
        R[j][0] = arr[m + 1+ j][0];
        R[j][1] = arr[m + 1+ j][1];
    }


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i][0] <= R[j][0])
        {
            arr[k][0] = L[i][0];
            arr[k][1] = L[i][1];
            i++;
        }
        else
        {
            arr[k][0] = R[j][0];
            arr[k][1] = R[j][1];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k][0] = L[i][0];
        arr[k][1] = L[i][1];
        i++;
        k++;
    }


    while (j < n2)
    {
        arr[k][0] = R[j][0];
        arr[k][1] = R[j][1];
        j++;
        k++;
    }
}


void mergeSort(ld arr[][2], int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

int main(){
  int n ; cin >> n ;
  ld arr[n][2] ;
  ld x , y ;
  for(int i=0 ; i<n; i++){
    cin >> x >> y ;
    arr[i][1] = i ;
    if(y == 0.0){
        if(x > 0.0) arr[i][0] = 0.0 ;
        else arr[i][0] = 180.0 ;
    }
    else if(x == 0.0){
        if(y > 0.0) arr[i][0] = 90.0 ;
        else arr[i][0] = 270.0 ;
    }
    else if(x>0.0 && y >0.0){
         arr[i][0] = atan(y/x)* 180 / PI;
    }
    else if(x < 0.0 && y>0.0){
         arr[i][0] = 180.0 - (atan(y/(-1*x))* 180 / PI) ;
    }
    else if(x < 0.0 && y<0.0){
         arr[i][0] = (atan(y/x)* 180 / PI) + 180.0;
    }else{
         arr[i][0] = 360.0 - (atan((-1*y)/x)* 180 / PI) ;
    }
  //  cout << arr[i][0] << "\n";
  }

  mergeSort(arr,0,n-1);
  ld mn = arr[1][0]-arr[0][0] , val;
  mn = min(mn , 360.0-mn) ;
  int v1 = arr[0][1], v2 = arr[1][1] ;
  for(int i=2 ; i<n ; i++){
     val = arr[i][0] - arr[i-1][0] ;
     val = min(val , 360.0-val);
     if(val < mn){
        mn = val ;
        v1 = arr[i-1][1] ;
        v2 = arr[i][1] ;
     }
  }
  val = abs(arr[0][0]-arr[n-1][0]);
  val = min(val , 360.0-val);
  if(val < mn)
  {
      v1 = arr[0][1] ;
      v2 = arr[n-1][1] ;
  }
  printf("%d %d\n",v1+1 , v2+1);
  return 0 ;
}