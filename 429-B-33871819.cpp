#include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;

  int a[1000][1000];
  int A_forward[1000][1000],A_backward[1000][1000];
  int B_forward[1000][1000],B_backward[1000][1000];


	int main(){
		int n,m;
		scanf("%d%d",&n,&m);

    for(int i=0; i<n ;i++){
        for(int j=0;j<m;j++){
        	scanf("%d",&a[i][j]);
        }
    } 
    

    A_forward[0][0]=a[0][0];
    for(int j=1;j<m;j++) A_forward[0][j] = a[0][j] + A_forward[0][j-1];
    for(int i=1;i<n;i++) A_forward[i][0] = a[i][0] + A_forward[i-1][0];
    for(int i=1;i<n;i++){
    	for(int j=1;j<m;j++){
    		 A_forward[i][j] = a[i][j]+ max(A_forward[i][j-1],A_forward[i-1][j]);
    	}
    } 


    A_backward[n-1][m-1] = a[n-1][m-1];
    for(int i=n-2;i>=0;i--) A_backward[i][m-1] = a[i][m-1] + A_backward[i+1][m-1];
    for(int j=m-2;j>=0;j--) A_backward[n-1][j] = a[n-1][j] + A_backward[n-1][j+1];
    for(int i=n-2;i>=0;i--){
    	 for(int j=m-2;j>=0;j--){
    	 	  A_backward[i][j] = a[i][j]+max( A_backward[i][j+1], A_backward[i+1][j]);
    	 }
    }




    B_forward[n-1][0]= a[n-1][0];
    for(int i=n-2;i>=0;i--) B_forward[i][0] = a[i][0] + B_forward[i+1][0];
    for(int j=1;j<m;j++) B_forward[n-1][j] = a[n-1][j] + B_forward[n-1][j-1];
    for(int i=n-2;i>=0;i--){
    	for(int j=1;j<m;j++){
    		B_forward[i][j] = a[i][j] + max(B_forward[i][j-1],B_forward[i+1][j]);
    	}
    }


    B_backward[0][m-1] = a[0][m-1];
    for(int i=1;i<n;i++) B_backward[i][m-1] = a[i][m-1] + B_backward[i-1][m-1];
    for(int j=m-2;j>=0;j--) B_backward[0][j] = a[0][j] + B_backward[0][j+1];
    for(int i=1;i<n;i++){
    	for(int j=m-2;j>=0;j--){
    		B_backward[i][j] = a[i][j]+ max(B_backward[i][j+1],B_backward[i-1][j]);
    	}
    }

 
    int mx=0;
    for(int i=1;i<n-1;i++){
    	for(int j=1;j<m-1;j++){
    		int a11,a12,a21,a22,b11,b12,b21,b22;

    		if(i==0&&j==0){ a11=0; a12=0; }
    		if(i>0&&j>0){a11 = A_forward[i-1][j]; a12 = A_forward[i][j-1];}
    		else if(i==0){a11 = 0; a12 = A_forward[0][j-1];}
    		else { a11 = A_forward[i-1][0]; a12=0;}

    		if(i==n-1 && j==m-1){ a21=0; a22=0;}
    		else if(i==n-1){a21 = 0; a22= A_backward[n-1][j+1];}
    		else if(j==m-1){a21 = A_backward[i+1][m-1]; a22=0;}
    		else {a22 = A_backward[i][j+1]; a21 = A_backward[i+1][j];}

    		if(i==n-1 && j==0) {b11=0; b12=0;}
    		else if(i==n-1) {b11=0;  b12=B_forward[n-1][j-1];}
    		else if(j==0) {b11 = B_forward[i+1][0]; b12=0;}
    		else {b12 = B_forward[i][j-1]; b11=B_forward[i+1][j];}

    		if(i==0&&j==m-1) {b21=0; b22=0;}
    		else if(i==0) {b21=0; b22 = B_backward[0][j+1];}
    		else if(j==m-1) {b21 = B_backward[i-1][m-1]; b22=0;}
    		else {b22 = B_backward[i][j+1]; b21=B_backward[i-1][j];}

    		int sm1 = a11+a21+b12+b22;
    		int sm2 = a12+a22+b11+b21;
    		mx = max(mx,max(sm1,sm2));
    	}
    }

    printf("%d\n",mx);
		return 0;
	}