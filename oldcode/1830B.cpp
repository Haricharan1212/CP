// Haricharan
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
#define vb vector<bool>
#define pi pair<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct chash
{
    int operator()(pi x) const { return x.first * 31 + x.second; }
};

void solve()
{
    int n;
    cin >> n;

    int lim = sqrt(2 * n) + 3;

    vector<pi> a(n);

    rep(i, 0, n)
    {
        cin >> a[i].first;
    }
    rep(i, 0, n)
    {
        cin >> a[i].second;
    }

    sort(a.begin(), a.end());

    map<int, int> m[lim + 1];

    // gp_hash_table<pi, int, chash> m;

    // int m[lim + 1][n + 1];

    // for (int i = 0; i <= lim; i++)
    //     for (int j = 0; j <= n; j++)
    //         m[i][j] = 0;

    long long ans = 0;
    rep(i, 0, n)
    {
        for (int ai = 1; ai <= min(lim, a[i].first); ai++)
        {
            int bi = a[i].first * ai - a[i].second;

            if (bi > n)
                break;
            if (bi < 0 || bi > n)
                continue;
            if (ai > lim || ai < 0)
                continue;

            if (m[ai].find(bi) != m[ai].end())
                ans += m[ai][bi];
        }

        // if (a[i].first <= lim)
        //     m[a[i].first][a[i].second]++;

        if (a[i].first <= lim)
            m[a[i].first][a[i].second]++;
    }

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