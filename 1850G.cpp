// Haricharan
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define vb vector<bool>
#define pi pair<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)

void solve()
{
    int n;
    cin >> n;

    map<int, int> x, y, xpy, xmy;

    rep(i, 0, n)
    {
        int a, b;
        cin >> a >> b;
        x[a]++;
        y[b]++;
        xpy[a + b]++;
        xmy[a - b]++;
    }

    int ans = 0;

    for (auto i : x)
        ans += (i.second * (i.second - 1));

    for (auto i : y)
        ans += (i.second * (i.second - 1));

    for (auto i : xpy)
        ans += (i.second * (i.second - 1));

    for (auto i : xmy)
        ans += (i.second * (i.second - 1));

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();

    return 0;
}
