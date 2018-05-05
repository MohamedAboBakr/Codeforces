#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdio.h>
#include<bits/stdc++.h>

using namespace std;

#define N 200001

int arr[N] ;
int sizeOfcomb[N] ;
int connected_comp = N ;
int flag[N] = {0};
int circle = 0 , root;



void initialize(){
  for(int i=0 ; i<N ; i++){
     arr[i] = i ;
     sizeOfcomb[i] = 1 ;
  }
}

int Find(int a){
   if(arr[a] == a) return a;
   // path compression
   return arr[a] = Find(arr[a]);
}


bool Is_connect(int a , int b){
    int parent1 = Find(a);
    int parent2 = Find(b);
    if(parent1 == parent2) return true;
    return false ;
}

void Union(int a , int b){
    if(Is_connect(a,b)) {
            root = Find(a);
            flag[root] = 1 ;
            return ;
    }
    connected_comp -- ;
    int parent1 = Find(a);
    int parent2 = Find(b);
   // printf("%d %d %d %d\n" , a , b , parent1 , parent2);
    if(flag[parent2] == 1) flag[parent1] = 1;
    else if(flag[parent1] == 1)flag[parent2] =1 ;
    arr[parent1] = parent2 ;
    sizeOfcomb[parent2] += sizeOfcomb[parent1] ;

}

int sizeOfelem_comp(int a){
    return sizeOfcomb[Find(a)];
}

void merge(int arr[][2], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1][2], R[n2][2];

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
        if ((L[i][0] < R[j][0])  || (L[i][0] == R[j][0] && L[i][1] < R[j][1]))
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


void mergeSort(int arr[][2], int l, int r)
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

  initialize();
  int n , curr_size = 0 ;
  cin >> n ;
  int nums[n][2] , ar[n];
  for(int i=0 ; i<n ; i++){
    cin >> nums[i][0]; nums[i][1] = i ;
    ar[i] = nums[i][0];

  }
  mergeSort(nums , 0 , n-1);
   int ans[n] ;

   for(int i=n-1 ; i>=0 ; i--){

      int elem  = nums[i][0] ;
      int index = nums[i][1];
      // printf("%d %d\n" , elem , index);
      if(index > 0){
         if(ar[index-1] >= elem) Union(index , index-1);
      }
      if(index < n-1) {
         if(ar[index+1] > elem)  Union(index , index+1);
      }

      int size = sizeOfelem_comp(index);
      if(size > curr_size){
         for(int j=curr_size ; j<size ; j++){
            ans[j] = elem ;
         }
         curr_size = size ;
      }
   }

   for(int i=0 ; i<n; i++){
     printf("%d ",ans[i]);
   }
}