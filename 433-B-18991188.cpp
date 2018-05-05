#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

void merge(ll arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    ll L[n1], R[n2];

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

void mergeSort(ll arr[], int l, int r)
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
  ll arr[n+1] ; arr[0] = 0 ;
  ll dp1[100001] ={0};
  ll dp2[100001] ={0};
  for(int i=1; i<=n ; i++){
    cin >> arr[i] ;
    dp1[i] = arr[i];
    dp1[i] += dp1[i-1] ;
  }
  mergeSort(arr ,0 ,n);
  for(int i=1; i<=n ; i++){
   // printf("%lld\n",arr[i]);
    dp2[i] = arr[i];
    dp2[i] += dp2[i-1] ;
  }
  int m ,t,r,l; cin>>m ;
  for(int i=0 ; i<m ; i++){
    cin >> t >> l >> r ;
    if(t == 1){
        cout << dp1[r]-dp1[l-1] << "\n";
    }else{
        cout << dp2[r]-dp2[l-1] << "\n";
    }
  }
  return 0 ;
}