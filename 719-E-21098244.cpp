#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;

ll mod = 7+1e9;
#define MAX 262150
int arr[100005] ;
ll lazy2[MAX] ;
int tree[MAX][2];

struct matrix{
     int arr[2][2];
     matrix(){
         arr[0][0] = arr[0][1] = arr[1][0] = arr[1][1]  = 0 ;
     }

     void mk(){
         arr[0][0] = 0;
         arr[0][1] = arr[1][0] = arr[1][1]  = 1 ;
     }

     void mk2(){
         arr[0][0] = arr[1][1] = 1;
         arr[1][0] = arr[0][1]  = 0 ;
     }

     matrix operator*(matrix b){
          matrix ans ;
          for(int i=0 ; i<2 ; i++){
             for(int j=0 ; j<2 ; j++){
                  for(int k=0; k<2 ; k++){
                     ans.arr[i][j] = (ans.arr[i][j]+ ((ll)arr[i][k]*b.arr[k][j])%mod)%mod ;
                  }
             }
          }

          return ans ;
     }

     matrix operator+(matrix b){
        matrix ans ;
        for(int i=0 ; i<2 ; i++){
             for(int j=0 ; j<2 ; j++){
                     ans.arr[i][j] = (arr[i][j]+b.arr[i][j])%mod ;
             }
          }
          return ans ;
     }

     int fib(){
         return arr[0][1] ;
     }

} lazy[MAX] , freee ,mtxx;


matrix pow_matrix(int p){

         matrix a = mtxx;

    if(p == 1){
            return a;
    }
         matrix b = mtxx;
          p-- ;
          while(p>0)
		  {
			if(p&1)a=a*b;
			b=b*b;
			p>>=1;
		  }
		return a;
}


void multi2(int index , int v1 , int v2 , matrix mtx){
      tree[index][0] = ((1LL*mtx.arr[0][0]*v1)%mod + (1LL*mtx.arr[0][1]*v2)%mod)%mod ;
      tree[index][1] = ((1LL*mtx.arr[1][0]*v1)%mod + (1LL*mtx.arr[1][1]*v2)%mod)%mod ;
}

void setLazy(int si ,int l , int r){
       if(lazy2[si]==0) return  ;
       multi2( si , tree[si][0] , tree[si][1] , lazy[si]);
       if( l != r){
              lazy[si*2 + 1]  = lazy[si*2 + 1]*lazy[si];
              lazy[si*2 + 2]  = lazy[si*2 + 2]*lazy[si];

              lazy2[si*2 + 1] =1 ;
              lazy2[si*2 + 2] =1 ;
       }
       lazy[si].mk2() ;
       lazy2[si] = 0 ;
}

void updateRangeUtil(int si, int ss, int se, int us,
                     int ue, matrix mtx)
{
    setLazy(si,ss,se);
    if (ss>se || ss>ue || se<us)
        return ;

    if (ss>=us && se<=ue)
    {

        multi2( si , tree[si][0] , tree[si][1] , mtx);
        if (ss != se)
        {
        lazy[si*2 + 1]  = lazy[si*2 + 1]*mtx;
        lazy[si*2 + 2]  = lazy[si*2 + 2]*mtx;
        lazy2[si*2 + 1] =1;
        lazy2[si*2 + 2] =1;
        }
        return;
    }


    int mid = (ss+se)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, mtx);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, mtx);

    tree[si][0] = (tree[si*2+1][0] + tree[si*2+2][0])%mod;
    tree[si][1] = (tree[si*2+1][1] + tree[si*2+2][1])%mod;

}


int getSumUtil(int ss, int se, int qs, int qe, int si)
{

   setLazy(si,ss,se);
    if (ss>se || ss>qe || se<qs)
        return 0;

    if (ss>=qs && se<=qe)
        return tree[si][0];

    int mid = (ss + se)/2;
    return (getSumUtil(ss, mid, qs, qe, 2*si+1) + getSumUtil(mid+1, se, qs, qe, 2*si+2))%mod;
}


void constructSTUtil(int ss, int se, int si)
{
    if (ss > se)
        return ;

    if (ss == se)
    {
        multi2( si , 0 , 1 , pow_matrix(arr[ss]));
        return;
    }

    int mid = (ss + se)/2;
    constructSTUtil(ss, mid, si*2+1);
    constructSTUtil(mid+1, se, si*2+2);

    tree[si][0] = (tree[si*2 + 1][0]+tree[si*2 + 2][0])%mod;
    tree[si][1] = (tree[si*2 + 1][1]+tree[si*2 + 2][1])%mod;

}


int main()
{
    freee.mk2() ; mtxx.mk();
    for(int i=0 ; i<MAX ; i++){
      lazy[i] = freee ;
   }
    int n,m,t,l,r; scanf("%d%d",&n,&m);
    for(int i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }
    constructSTUtil(0, n-1, 0);
    int dif ;
    for(int i=0; i<m ; i++){
        scanf("%d%d%d",&t,&l,&r);
        if(t == 1){
            scanf("%d",&dif);
            updateRangeUtil(0, 0, n-1, l-1,r-1, pow_matrix(dif));

        }else{
           printf("%d\n",getSumUtil(0, n-1, l-1, r-1, 0));

        }
    }
    return 0;
}