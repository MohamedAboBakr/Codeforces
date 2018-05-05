#include <cstdio>
#include <vector>
#include <string.h>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r)
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
  int arr[n] ;
  int f = 1 ;
  cin >> arr[0];
  for(int i=1 ; i<n ; i++){
     cin >> arr[i];
     if(arr[i] != arr[i-1]) f=0 ;
  }

  if(f==1){
     printf("%d",arr[0]);
     for(int i=1 ; i<n ; i++){
         printf(" %d",arr[i]);
     }
     printf("\n");
     return 0;
  }
  mergeSort(arr , 0 , n-1);
    if(n%2 == 0){
       printf("%d %d" , arr[n/2-1] , arr[n/2]);
       int i=0 , j= n/2 + 1 ;
       while(i < n/2-1){
         printf(" %d %d" , arr[i] , arr[j]);
         i++ ; j++ ;
       }
       printf("\n");
       return 0 ;
  }

  printf("%d" , arr[n/2]);
  int i=0 , j = n/2 + 1 ;
  while(i < n/2){
        printf(" %d %d" , arr[j] , arr[i]);
         i++ ; j++ ;
  }
  printf("\n");
 return 0;
}