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
    int n, d12, d23, d31;
    cin >> n >> d12 >> d23 >> d31;

    if (2 * max(max(d12, d31), d23) > d12 + d23 + d31 || (d12 + d23 + d31) % 2)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;

    si left;
    rep(i, 4, n + 1) left.insert(i);

    vector<pi> edges;

    if (d23 >= d31 && d23 >= d12)
    {
        int comlength = (d12 + d31 - d23) / 2;
        rep(i, 0, comlength)
        {
        }
    }
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
