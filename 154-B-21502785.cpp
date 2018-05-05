#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

vector<int> primes ;
bool flag[100005];
map <int , int> activate ;
bool act[100001];
int sz ;
void sieve(){

     int i=2 ;
     for(; i< 317 ; i++){
             if(!flag[i]){
                 for(int j=2*i ; j< 100001 ; j+= i){
                    flag[j] = true ;
                 }
             }
     }
}


void activate_(int k){

      if(act[k]) {
           printf("Already on\n");
           return ;
      }

      if(k == 1){
          act[1] = true;
          printf("Success\n");
         return ;
      }

      if(!flag[k]) {
         if(activate[k] != 0){
                       printf("Conflict with %d\n",activate[k]);
                       return  ;
         }
         act[k] = true ;
         activate[k] = k ;
         printf("Success\n");
         return ;
      }

      int srt = (int)sqrt(k);
      vector <int> want ;
      for(int i=2; i<= srt ; i++){
            if(k%i == 0){
                   if(!flag[i]){
                   want.push_back(i);
                   if(activate[i] != 0){
                       printf("Conflict with %d\n",activate[i]);
                       return  ;
                   }
                   }
                   if(!flag[k/i]){
                       want.push_back(k/i);
                       if(activate[k/i] != 0){
                           printf("Conflict with %d\n",activate[k/i]);
                           return  ;
                      }
                   }
           }
      }
      printf("Success\n");
      act[k] = true ;
      for(int i=0 ; i< want.size(); i++){
          activate[want[i]] = k ;
      }
 }

 void deactivate(int k){
     if(!act[k]){
          printf("Already off\n");
          return ;
     }

     if(k == 1){
          act[1] = false;
          printf("Success\n");
          return ;
      }

     printf("Success\n");
     act[k] = false ;

     if(!flag[k]){
           activate[k] = 0 ;
           return ;
     }

     int srt = (int)sqrt(k);
     for(int i=2 ; i<= srt ; i++){

           if(k%i == 0){
                   if(!flag[i]) activate[i] = 0 ;
                   if(!flag[k/i]) activate[k/i] = 0 ;
           }
      }

 }


int main(){
  sieve();

  int n,m,k; scanf("%d%d",&n,&m); getchar();
  char c ;
  for(int i=0; i<m ; i++){
         scanf("%c%d",&c,&k); getchar();
         if(c == '+') activate_(k);
         else deactivate(k);
  }
  return 0 ;
}