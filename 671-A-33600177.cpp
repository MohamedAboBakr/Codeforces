#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair<double,int> pd;

double epsilon=1.0E-12;
bool essentiallyEqual(double a, double b)
{
    return fabs(a - b) <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

bool definitelyGreaterThan(double a, double b)
{
    return (a - b) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

bool definitelyLessThan(double a, double b)
{
    return (b - a) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

double distance(int x1,int y1,int x2,int y2){
   ld diffx = x1-x2;
   ld diffy = y1-y2;
   return (double)sqrt(diffx*diffx+diffy*diffy);
}


int main(){

  int ax,ay,bx,by,tx,ty;
  int n,xi,yi;
  double da,db,dt,ra,rb;
  ld mn =0.0;
  int bott1=-1,bott2=-1;
  vector<pd> firstA,firstB;
  vector<int> xs,ys;

  scanf("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&tx,&ty);
  scanf("%d",&n);

  for(int i=0;i<n;i++){
     scanf("%d%d",&xi,&yi);
     xs.push_back(xi); ys.push_back(yi);
     da = distance(ax,ay,xi,yi);
     db = distance(bx,by,xi,yi);
     dt = distance(tx,ty,xi,yi);
	    ra = dt*2.0-(dt+da);
	    firstA.push_back({ra,i});
	    rb = dt*2.0-(dt+db);
	    firstB.push_back({rb,i});  
  }


  sort(firstA.begin(),firstA.end());
  sort(firstB.begin(),firstB.end());

  int sz1 = firstA.size();
  int sz2 = firstB.size();
  
  if(definitelyLessThan(firstA[sz1-1].first,0.0)&&definitelyLessThan(firstB[sz2-1].first,0.0)){
  	 if(definitelyGreaterThan(firstA[sz1-1].first,firstB[sz2-1].first)){
  	 	  bott1 = firstA[sz1-1].second;
  	 	  mn += distance(ax,ay,xs[bott1],ys[bott1]);
  	 	  mn += distance(tx,ty,xs[bott1],ys[bott1]);
  	 }else{
   	 	  bott1 = firstB[sz2-1].second;
  	 	  mn += distance(bx,by,xs[bott1],ys[bott1]);
  	 	  mn += distance(tx,ty,xs[bott1],ys[bott1]); 	 	
  	 }

  }
  else if(definitelyLessThan(firstA[sz1-1].first,0.0)){
  	    bott1 = firstB[sz2-1].second;
  	 	  mn += distance(bx,by,xs[bott1],ys[bott1]);
  	 	  mn += distance(tx,ty,xs[bott1],ys[bott1]); 	 
  }
  else if(definitelyLessThan(firstB[sz2-1].first,0.0)){
  	    bott1 = firstA[sz1-1].second;
  	 	  mn += distance(ax,ay,xs[bott1],ys[bott1]);
  	 	  mn += distance(tx,ty,xs[bott1],ys[bott1]); 	 
  } 
  else{
  	 if(firstA[sz1-1].second != firstB[sz2-1].second){
  	 	 bott1 = firstA[sz1-1].second;
  	 	 bott2 = firstB[sz2-1].second;
  	 	 mn += distance(ax,ay,xs[bott1],ys[bott1]);
  	 	 mn += distance(tx,ty,xs[bott1],ys[bott1]);
  	 	 mn += distance(bx,by,xs[bott2],ys[bott2]);
  	 	 mn += distance(tx,ty,xs[bott2],ys[bott2]);
  	 }else{
  	 	 double d1 = firstA[sz1-1].first;
  	 	 if(sz2>1&&definitelyGreaterThan(firstB[sz2-2].first,0.0)) d1 += firstB[sz2-2].first;
  	 	 double d2 = firstB[sz2-1].first;
  	 	 if(sz1>1&&definitelyGreaterThan(firstA[sz1-2].first,0.0)) d2 += firstA[sz1-2].first;
       if(definitelyGreaterThan(d1,d2)){
            bott1 = firstA[sz1-1].second;
  	 	    bott2 = (sz2>1&&definitelyGreaterThan(firstB[sz2-2].first,0.0))?firstB[sz2-2].second:-1; 
  	 	    mn += distance(ax,ay,xs[bott1],ys[bott1]);
  	 	    mn += distance(tx,ty,xs[bott1],ys[bott1]);
  	 	    if(bott2!=-1){
  	 	      mn += distance(bx,by,xs[bott2],ys[bott2]);
  	 	      mn += distance(tx,ty,xs[bott2],ys[bott2]); 	 	    	
  	 	     }
        }else{
            bott1 = firstB[sz2-1].second;
  	 	    bott2 = (sz1>1&&definitelyGreaterThan(firstA[sz1-2].first,0.0))?firstA[sz1-2].second:-1; 
  	 	    mn += distance(bx,by,xs[bott1],ys[bott1]);
  	 	    mn += distance(tx,ty,xs[bott1],ys[bott1]);
  	 	    if(bott2!=-1){
  	 	      mn += distance(ax,ay,xs[bott2],ys[bott2]);
  	 	      mn += distance(tx,ty,xs[bott2],ys[bott2]);        
          }
  	    }
  	  }
  }



  for(int i=0;i<n;i++){
      if((i!=bott1)&&(i!=bott2)){
      	mn += distance(tx,ty,xs[i],ys[i])*2.0;
      }
  }
  cout << setprecision(9) << mn << "\n";
	return 0;
}