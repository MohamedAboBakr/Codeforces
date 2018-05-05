#include <climits>
#include <math.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll mx = 1e7 ;

void merge(ll arr[][2], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    ll L[n1][2], R[n2][2];


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


void mergeSort(ll arr[][2] , int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void summ(ll arr[][2] , int n , int k){
   int index = min(n-1,k);
   for(int i=1 ; i<=index ; i++){
    arr[i][0] += arr[i-1][0] ;
   }
}

int check(ll dol[][2], int c1 , ll pon[][2] , int c2 , int k , ll s , ll d_price , ll p_price ,int* d_index , int* p_index){
     int index = min(c1,k);
     for(int i=0 ; i<= index ; i++){
         int p = k-i ;
         if(p <= c2){
             if(dol[i][0]*d_price + pon[p][0]*p_price <= s){
                    *d_index = i ;
                    *p_index = p ;
                    return 1 ;
             }
         }
     }
     return 0 ;
}

int BS(ll doll[][2] , ll ponn[][2] , ll dol[][2], int c1 , ll pon[][2] , int c2 , int k , ll s , int* d_index , int* p_index , int l , int r){

     int lf = l , rt = r , md;
     int ans = -1 ;
     while(lf <= rt){
         md = (lf+rt) /2 ;
         int mnD = doll[md][0] ;
         int mnP = ponn[md][0] ;
         int ch = check(dol , c1 , pon , c2 , k , s , mnD , mnP , d_index , p_index);
         if(ch == 1){
           ans = md ;
           rt = md-1;
         }
         else {
             lf = md+1 ;
         }
     }
 return ans ;
 }
int main(){
  ll n , m , k, s , d,p ;
  cin >> n >> m >> k >> s ;
  ll dollar[n+1][2] , pound[n+1][2] ;
  dollar[0][0] = mx ; dollar[0][1] = 0 ;
  pound [0][0] = mx ; pound [0][1] = 0 ;
  for(int i=1 ; i<=n ; i++){
     cin >> d;
     if(d < dollar[i-1][0]){
        dollar[i][0] = d ;
        dollar[i][1] = i ;
     }else{
        dollar[i][0] = dollar[i-1][0] ;
        dollar[i][1] = dollar[i-1][1] ;
      }
  }

 for(int i=1 ; i<=n ; i++){
     cin >> p;
     if(p < pound[i-1][0]){
        pound[i][0] = p ;
        pound[i][1] = i ;
     }else{
        pound[i][0] = pound[i-1][0] ;
        pound[i][1] = pound[i-1][1] ;
      }
  }

  ll dollar_gat[m+1][2] , pound_gat[m+1][2] ;
  int c1 = 1 , c2 = 1 , t;
  ll val ;
  dollar_gat[0][0] = 0 ;
  pound_gat [0][0]  = 0 ;
  for(int i=1 ; i<=m ; i++){
       cin >> t >> val ;
       if(t == 1) {
            dollar_gat[c1][0] = val ;
            dollar_gat[c1][1] = i ;
            c1++;
       }
       else {
           pound_gat[c2][0] = val ;
           pound_gat[c2][1] = i ;
           c2++ ;
       }
  }
  mergeSort(dollar_gat , 1 , c1-1);
  summ(dollar_gat , c1 , (int)k) ;

  mergeSort(pound_gat , 1 , c2-1);
  summ(pound_gat , c2 , (int)k) ;

  int d_index , p_index ;
  int ans = BS(dollar , pound , dollar_gat , c1-1 , pound_gat , c2-1 , k , s , &d_index , &p_index , 1 , n);
  if(ans == -1){
    printf("-1\n");
    return 0 ;
  }
  printf("%d\n" ,  ans );
  ll d_day = dollar[ans][1] ;
  ll p_day = pound [ans][1] ;
  for(int i=1 ; i<= d_index ; i++){
     printf("%lld %lld\n" , dollar_gat[i][1] , d_day );
  }

  for(int i=1 ; i<= p_index ; i++){
     printf("%lld %lld\n" , pound_gat[i][1] , p_day );
  }

  return 0 ;
}