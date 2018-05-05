#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int is_vowel(char c){
	return (c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u');
}

int main(){
	string s; cin>>s;
	int n = s.size();
	vector<string> non_typo;
	char c1='.', c2='.';
	string ss="";
  int len =0;
	for(int i=0;i<n;i++){
		 string si(1,s[i]);
     if(is_vowel(s[i])){
     	 ss+=si;
     	 c1='.'; c2='.';
     	 len=0;
     }
     else{
     	if(c1=='.'){c1=s[i]; ss+=si; len++;}
      
      else{
      	if(s[i]==c1){
             if(c2=='.'){
             	  ss+=si;
             	  len++;
             }else{
             	  if(len>=2){
                  non_typo.push_back(ss);
                  ss=si;
                  len=1;
                  c1=s[i]; c2='.';
             	  }else{
             	  	ss+=si;
             	  	len++;
             	  }
             }
      	}else{
            if(len>=2){
            	non_typo.push_back(ss);
            	ss=si;
            	len=1;
            	c1=s[i]; c2='.';
            }else{
            	len++;
            	ss+=si;
            	c2 = s[i];
            }
      	}
      }
     
     }
	}
	non_typo.push_back(ss);

	for(int i=0;i<non_typo.size();i++){
      cout<< non_typo[i];
      if(i<non_typo.size()-1) cout << " ";
      else cout<< "\n";
	}
	return 0;
}