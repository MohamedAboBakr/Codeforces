#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;

    int x,y,z;
    cin >> x >> y >> z;

    int la = a-x>0?(a-x)/2:(a-x);
    int lb = b-y>0?(b-y)/2:(b-y);
    int lc = c-z>0?(c-z)/2:(c-z);

    if(la + lb + lc >= 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}