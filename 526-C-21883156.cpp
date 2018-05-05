#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main(){
 ll c,wb,wr,hb,hr ;
 scanf("%lld%lld%lld%lld%lld",&c,&hr,&hb,&wr,&wb);
 ll srt = (ll)sqrt(c);
 ll mxx =0;
 if(wb > srt){
       for(int i=0 ; i<= c/wb ; i++){
          ll curr = i*hb + (c-wb*i)/wr*hr ;
          mxx = max(curr , mxx);
       }
       printf("%lld\n",mxx);
       return 0;
 }

 if(wr > srt){
       for(int i=0 ; i<= c/wr ; i++){
          ll curr = i*hr + (c-wr*i)/wb*hb ;
          mxx = max(curr , mxx);
       }
       printf("%lld\n",mxx);
       return 0 ;
 }

 if(wb*hr >= wr*hb){

     for(int i=0;i<wr;i++){
         ll curr = i*hb + (c-i*wb)/wr*hr ;
         mxx = max(curr , mxx);
     }
     printf("%lld\n",mxx);
    return 0 ;

 }

 for(int i=0;i<wb;i++){
         ll curr = i*hr + (c-i*wr)/wb*hb ;
         mxx = max(curr , mxx);
     }
printf("%lld\n",mxx);

  return 0 ;
}