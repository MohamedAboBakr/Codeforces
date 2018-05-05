#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
ll mod  =  7+1e9;

ll  Power(ll x , ll t){
   ll ans=1;
	while(t>0)
	{
		if(t&1)ans=ans*x%mod;
		x=x*x%mod;
		t>>=1;
	}
	return ans;
}


struct real_number
{
	ll x,y;
	real_number(ll _x=0,ll _y=0){x=_x;y=_y;}
	real_number operator+(real_number t){return real_number((x+t.x)%mod,(y+t.y)%mod);}
	real_number operator-(real_number t){return real_number((x-t.x+mod)%mod,(y-t.y+mod)%mod);}
	real_number operator*(real_number t){return real_number((1ll*x*t.x+1ll*y*t.y*5)%mod,(1ll*x*t.y+1ll*y*t.x)%mod);}
	real_number operator*(ll t){return real_number((1ll*x*t)%mod,(1ll*y*t)%mod);}
	bool operator!=(real_number t){return x!=t.x||y!=t.y;}
	real_number inv()
	{
		ll t=(1ll*x*x%mod-5ll*y*y%mod+mod)%mod;
		t=Power(t,mod-2);
		return real_number(x*t%mod,(-y*t%mod+mod)%mod);
	}
	void operator=(ll t){x=t;y=0;}
	real_number operator^(ll t)
	{
		real_number ret(1,0),b=(*this);
		while(t>0)
		{
			if(t&1)ret=ret*b;
			b=b*b;
			t>>=1;
		}
		return ret;
	}
	void out(){cout<<x<<","<<y<<endl;}
};

ll stirling[205][205] ;
ll fact[205] , inv[205];

real_number alpha , theta , pow_alpha[205] , pow_theta[205];

ll nCr(ll n , ll r){
      if(n<r) return 0 ;
      return (((fact[n]*inv[r])%mod)*inv[n-r])%mod ;
}

ll sign(ll n){return n&1? mod-1:1;}

real_number summation(real_number x,ll l,ll r)
{
	if(x.x==1&&x.y==0)return (r-l+1)%mod;
	real_number ans = ((x^l)-(x^(r+1)))*(real_number(1,0)-x).inv();
    return ans ;
}

ll solve(ll k , ll l ,ll r){
       real_number ans ;
       real_number out_increase = 1 , five_inDom = real_number(0,Power(5,mod-2)) ;
       for(ll i=1 ; i<=k ; i++){
           out_increase = out_increase*five_inDom ;
           real_number inside_sum ;
           for(ll j=0 ; j<=i ; j++){
                inside_sum = inside_sum + summation(pow_alpha[j]*pow_theta[i-j] , l , r)*nCr(i,j)*sign(i-j) ;
           }
           inside_sum = inside_sum*out_increase ;
           inside_sum = inside_sum*stirling[k][i] ;
           ans = ans + inside_sum;
       }
       return ans.x ;
}

int main(){
   ll k,l,r ;
   scanf("%lld%lld%lld",&k,&l,&r);

   // pre_compute
   fact[0] = 1 ; inv[0] = 1 ;
   stirling[0][0] = 1;
   alpha = real_number(1,1)*Power(2,mod-2);   // (1+sqrt(5))/2
   theta = real_number(1,0)-alpha ;           // (1-sqrt(5))/2
   pow_alpha[0] = 1 ;  pow_theta[0] = 1 ;

   for (int i = 1; i <= 200 ; i++)
	{
	    fact[i] = (i*fact[i-1])%mod;
	    inv[i] = Power(fact[i] , mod-2);
		stirling[i][0] = 0;
		stirling[0][i] = 0;
		pow_alpha[i] = pow_alpha[i-1]*alpha ;
		pow_theta[i] = pow_theta[i-1]*theta ;
		for (int j = 1; j <= i; j++)
		{
			stirling[i][j] = ((-(i - 1)*stirling[i - 1][j])%mod + stirling[i - 1][j - 1]) % mod;
		}

	}

	l+=2 ; r+= 2 ;
	printf("%lld\n",((solve(k,l,r)%mod*inv[k])%mod + mod)%mod);

  return 0 ;
}