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
    int n, x;
    cin >> x >> n;

    vi a(n);

    multiset<int> cheaps;

    rep(i, 0, n)
    {
        cin >> a[i];
        cheaps.insert(a[i]);
    }

    int mincost = 1e18;

    // rep(i, 0, n)
    // {
    //     if (a[i] >= x)
    //     {
    //         mincost = min(mincost, a[i] * (i + 1));

    //     }
    // }

    rep(i, 0, n)
    {
        rep(j, i + 1, n)
        {
            if (a[i] + a[j] >= x)
            {
                mincost = min(mincost, a[i] * (i + 1) + a[j] * (j + 1));
            }
        }
    }
    int mx = 1e18;

    cout << (mincost == mx ? -1 : mincost) << endl;
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
