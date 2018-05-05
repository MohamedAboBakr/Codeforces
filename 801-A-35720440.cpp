#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
 string s;
 cin >> s;
 int ln = s.size();
 int f=0,c=0;
 for(int i=0;i<ln-1;i++){
       if(s[i]=='V'){
       	 if(s[i+1]=='K'){c++;i++;}
       	 else if(f==0&&(i+2==ln || (i+3<=ln && s[i+2]=='V'))){
       	 	f=1;
       	 	c++;
       	 	i++;
       	 }
       }else if(f==0&&s[i+1]=='K'){
          f=1;
          c++;
          i++;
       }
 }
 printf("%d\n",c);
 return 0;
}