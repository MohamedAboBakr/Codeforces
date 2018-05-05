#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#define s 1000000001

using namespace std;


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




int main(void) {



    vector<int> v ;
    int n  , counter = 1 , choose;
    long sum =  0L , m;
    scanf("%d%ld",&n , &m);
    int flag[n+1] ;

    flag[0] = 0 ;
    for (int i= 1 ; i<=n ; i++){
        scanf("%d",&choose);
        flag[i] = choose ;
    }

   mergeSort(flag , 0 , n);

    for(int i = 1 ; (i<=s) && (sum+i <= m); i++){
        if(counter <= n && flag[counter] == i){
            counter ++ ;
            continue ;
        }
      ///  printf("%ld\n",sum);
        v.push_back(i);
        sum += i ;
    }

   int si = v.size() ;
   printf("%d\n" , si);
   for(int i=0 ; i<si ; i++){
    printf("%d%s" , v[i] , (i == si-1) ? "\n" : " ");
   }
	return 0;
}