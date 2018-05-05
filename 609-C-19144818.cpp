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


int main()
{
    int n ; cin >> n ;
    ll arr[n] ;
    ll sum = 0L , m = 0L;
    for(int i=0 ; i<n ; i++){
       cin >> arr[i] ; sum += arr[i];
    }
    ll div = sum/n ;
    ll mx = sum%n ;
    ll mn = n-mx;
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        if(mn > 0){
            mn -- ;
            m += abs(div-arr[i]);
        }
        else{
            m += abs(div+1-arr[i]);
        }
    }
    cout << m/2 ;
    return 0 ;
}