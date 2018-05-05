#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

map<char,int> mp1;
map<int,char> mp2;

string vec_to_string(vector<int> vec, int lst){
     string s="";
     for(int i=0;i<vec.size() && (i<lst);i++){
       string ss(1,mp2[vec[i]]);
       s += ss;
     }
     return s;
}

void add_1(vector<int> &vec, int base, int *carry, int lst){
     for(int i=lst; i>=0; i--){
         int sum = vec[i]+ *carry;
         vec[i] = (sum==base)?0:sum;
         *carry = (sum==base)?1:0;
     }   
} 

int main(){
	int n, k,ind=0,base;
	scanf("%d%d",&n,&k); getchar();
	string s; cin >> s;
	set<char> sett;
	vector<int> vec;
	for(int i=0;i<n;i++) sett.insert(s[i]);
	base = sett.size();
  set<char>::iterator it = sett.begin();
  for(; it!=sett.end(); it++){
   mp1[*it] = ind;
   mp2[ind] = *it;
   ind++;
  }
  
  for(int i=0;i<n;i++){
     vec.push_back(mp1[s[i]]);
  }

  string ans ="" ;
  if(k>n){
     for(int i=n;i<k;i++){
        vec.push_back(0);
     }
     ans = vec_to_string(vec,k);
  }else {
  	 int carry=1;
     add_1(vec,base, &carry, k-1);
     if(carry==1) ans=string(1,mp2[0]);
     ans += vec_to_string(vec,k);
  }
  cout << ans << "\n";
	return 0;
}