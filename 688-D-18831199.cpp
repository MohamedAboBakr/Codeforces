#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <math.h>
#include<bits/stdc++.h>

using namespace std;
typedef long long int lli ;

int main() {
	lli n, k, lcm=1;
	lli   i, g;
	scanf("%lld %lld", &n, &k);
	for(i=0; i<n; ++i) {

		scanf("%lld", &g);

		lcm = lcm*g/__gcd(lcm, g);
		lcm = __gcd(lcm, k);
		if(lcm==k) {
			printf("Yes\n");
			return 0;
		}
	}

	printf("No\n");


}