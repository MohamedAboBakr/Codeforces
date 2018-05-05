#include <bits/stdc++.h>
using namespace std;
set<pair<int, int> > h;
int main() {
  long long x, y, a, b, sum;
  string s;
  cin >> x >> y >> a >> b >> s;
  sum = x * y;
  for (int i = 0; i < s.length(); i++) {
    if (h.find(make_pair(a, b)) == h.end()) {
      h.insert(make_pair(a, b));
      cout << 1 << " ";
      sum--;
    } else
      cout << 0 << " ";
    int dirX = s[i] == 'U' ? -1 : s[i] == 'D' ? 1 : 0;
    int dirY = s[i] == 'L' ? -1 : s[i] == 'R' ? 1 : 0;
    a += dirX, b += dirY;
    if (a > x || a < 1 || b > y || b < 1)
      a -= dirX, b -= dirY;
  }
  cout << sum;
  return 0;
}