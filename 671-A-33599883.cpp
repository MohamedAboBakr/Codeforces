#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair<ld,int> pd;

ld epsilon=1.0E-12;
bool essentiallyEqual(ld a, ld b)
{
    return fabs(a - b) <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

bool definitelyGreaterThan(ld a, ld b)
{
    return (a - b) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

bool definitelyLessThan(ld a, ld b)
{
    return (b - a) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

bool cmp(pd a , pd b){
    if(definitelyLessThan(a.first,b.first)) return true;
    return false;
}
ld distance(int x1,int y1,int x2,int y2){
   ld diffx = x1-x2;
   ld diffy = y1-y2;
   return sqrt(diffx*diffx+diffy*diffy);
}


int main(){

  int ax,ay,bx,by,tx,ty;
  int n,xi,yi;
  ld da,db,dt,ra,rb;
  ld mn =0.0,mn2=0.0;
  int bott1=-1,bott2=-1;
  vector<pd> firstA,firstB;

  scanf("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&tx,&ty);
  scanf("%d",&n);

  for(int i=0;i<n;i++){
     scanf("%d%d",&xi,&yi);
     da = distance(ax,ay,xi,yi);
     db = distance(bx,by,xi,yi);
     dt = distance(tx,ty,xi,yi);
     firstA.push_back({da-dt,i});
     firstB.push_back({db-dt,i});
     mn += 2.0*dt;  
  }

  
  sort(firstA.begin(),firstA.end(),cmp);
  sort(firstB.begin(),firstB.end(),cmp);

  int sz1 = firstA.size();
  int sz2 = firstB.size();
 if(definitelyGreaterThan(firstA[0].first,0.0) && definitelyGreaterThan(firstB[0].first,0.0)) mn2 = min(firstA[0].first,firstB[0].first);
 else{
			if(firstA[0].second != firstB[0].second){
				 ld mm=0.0; 
				 ld d1=firstA[0].first;
				 ld d2=firstB[0].first;
				 if(definitelyLessThan(d1,0.0)) mm+= d1;
			 if(definitelyLessThan(d2,0.0)) mm+= d2;
			 mn2 = mm;
			 
			}else{
				 ld mm1=0.0,mm2=0.0;
			     ld d1=firstA[0].first;
				 ld d2=firstB[0].first;
				 if(definitelyLessThan(d1,0.0)) mm1+= d1;
			 if(definitelyLessThan(d2,0.0)) mm2+= d2;  	 	 
				 if(sz2>1){
			     if(definitelyLessThan(firstB[1].first,0.0)) mm1+=firstB[1].first;
				 }
				 if(sz1>1) {
				 	   if(definitelyLessThan(firstA[1].first,0.0)) mm2+=firstA[1].first;
				 }
		     	 if(definitelyLessThan(mm1,mm2)) mn2 = mm1;
			     else mn2 = mm2;
			}
}

  mn += mn2;
  cout << setprecision(9) << mn << "\n";

	return 0;
}