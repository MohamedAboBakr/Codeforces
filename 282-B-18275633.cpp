#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define s 1000000

using namespace std;



void print_chrs(char arr[s] , int len){
    for(int i=0 ; i<len ; i++){
        printf("%c",arr[i]);
    }
    printf("\n");
}
void merge(int arr[][3], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1][3], R[n2][3];


    for (i = 0; i < n1; i++){
        L[i][0] = arr[l + i][0];
        L[i][1] = arr[l + i][1];
        L[i][2] = arr[l + i][2];
    }
    for (j = 0; j < n2; j++){
        R[j][0] = arr[m + 1+ j][0];
        R[j][1] = arr[m + 1+ j][1];
        R[j][2] = arr[m + 1+ j][2];
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
            arr[k][2] = L[i][2];
            i++;
        }
        else
        {
            arr[k][0] = R[j][0];
            arr[k][1] = R[j][1];
            arr[k][2] = R[j][2];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
            arr[k][0] = L[i][0];
            arr[k][1] = L[i][1];
            arr[k][2] = L[i][2];
        i++;
        k++;
    }

    while (j < n2)
    {
            arr[k][0] = R[j][0];
            arr[k][1] = R[j][1];
            arr[k][2] = R[j][2];
        j++;
        k++;
    }
}


void mergeSort(int arr[][3], int l, int r)
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

    int n ;
    long sum_G = 0L , sum_A = 0L;
    char chrs[s] ;
    scanf("%d",&n);
    int arr[n][3];
    for (int i=0 ; i<n ; i++){
        int ai , gi ;
        scanf("%d%d",&ai,&gi);
        arr[i][0] = ai ;
        arr[i][1] = gi ;
        arr[i][2] = i ;
        sum_G += gi ;
        chrs[i] = 'G'  ;
    }

   // printf("%d\n" ,sum_G);
    if(sum_G <= 500) {
        print_chrs(chrs , n);
        return 0 ;
    }

    long sum = 0L;
    mergeSort(arr , 0 , n-1);

    for(int i=0 ; i<n ; i++){
         sum_A += arr[i][0] ;
         sum_G -= arr[i][1] ;
         sum = sum_A - sum_G ;
         if(sum > 500){
            printf("-1\n");
            return 0 ;
         }

         chrs[arr[i][2]] = 'A' ;
         if(abs(sum) <= 500){
            print_chrs(chrs , n);
            return 0 ;
         }
    }

    if(abs(sum) <= 500){
            print_chrs(chrs , n);
         }
	return 0;
}