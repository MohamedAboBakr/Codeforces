#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
int comps[200005],socket[200005];
map< int , pair< int , vector < int > > > comp ;
map< int , vector < int > > unconnected ;
int main(){
   int n,m,c,s,mxx=0,mn =0;
   scanf("%d%d",&n,&m);
   for(int i=0;i<n;i++){
  //   comp[c] ={0,vector<int>()};
     scanf("%d",&c);
     comp[c].second.push_back(i);
     comp[c].first = 0;
  // printf("%d %d\n",comp[c].first , comp[c].second.size());
   }



   for(int i=0;i<m; i++){
      scanf("%d",&s);
      if(comp.find(s)!=comp.end() && comp[s].first<comp[s].second.size()){
          comps[comp[s].second[comp[s].first]] = i+1 ;
          comp[s].first++;
          if(comp[s].first == comp[s].second.size()){comp.erase(s); }
          mxx++ ;
      } else{
         unconnected[s].push_back(i);
      }
   }

   map< int , vector < int > >::iterator it = unconnected.begin();
   for(; it != unconnected.end() ;it++){
        int value = it->first ;
        vector <int> v ;
        while(value>0){
            v.push_back(value);
            if(value==1)break;
            value = (int)ceil(1.0*value/2);
        }
        for(int i=0 ; i<it->second.size();i++){
             int index = it->second[i] ;
             int flag=0,p=0,plug=0;
             for(;p<v.size();p++){
                 if(v[p] < comp.begin()->first) break ;
                 if(comp.find(v[p])!= comp.end() && comp[v[p]].first<comp[v[p]].second.size()){
                     flag=1;
                     comps[comp[v[p]].second[comp[v[p]].first]]=index+1 ;
                     comp[v[p]].first++;
                    if(comp[v[p]].first == comp[v[p]].second.size()){comp.erase(v[p]);}
                     socket[index]=p ;
                     mxx++;
                     mn += p ;
                     break;
                 }
             }
             if(flag == 0) break;
        }
   }

   printf("%d %d\n",mxx,mn);
   printf("%d",socket[0]);
   for(int i=1;i<m;i++){
      printf(" %d",socket[i]);
   }
   printf("\n");

   printf("%d",comps[0]);
   for(int i=1;i<n;i++){
      printf(" %d",comps[i]);
   }
   printf("\n");

   return 0;
}