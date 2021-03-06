#include <map>
#include <iostream>
#include <utility> //pair
using namespace std;


map <pair<long, long>, int> cnt;
long long ans = 0;

int main()
{

    int N;
    cin >> N;
    long x[N], y[N];
    for (int i = 1; i <= N; i++)
        cin >> x[i] >> y[i];
    for (int i = 1; i < N; i++)
    for (int j = i + 1; j <= N; j++)
    {
        ans += cnt[make_pair(x[i] + x[j], y[i] + y[j])];
        cnt[make_pair(x[i] + x[j], y[i] + y[j])]++;
    }
    cout << ans;
    return 0;
}