// Haricharan

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define vi vector<int>
#define vii vector<vector<int>>
#define pi pair<int, int>
#define mi map<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)
#define repr(var, r, l) for (int var = r; var > l; var--)
int mod1 = 1000000007;
int mod2 = 998244353;

bool check(pair<int, pi> a, pair<int, pi> b)
{
    if (b.first - a.first >= abs(b.second.first - a.second.first) + abs(b.second.second - a.second.second))
    {
        return true;
    }
    return false;
}

void solve()
{
    int r, n;
    cin >> r >> n;

    vi dp(n + 1, -1e18);
    vector<pair<int, pi>> v(n + 1);
    v[0] = {0, {1, 1}};

    rep(i, 1, n + 1)
    {
        int t, x, y;
        cin >> t >> x >> y;
        v[i] = {t, {x, y}};
    }

    dp[0] = 0;

    rep(i, 1, n + 1)
    {
        dp[i] = dp[i - 1];
        for (int j = i - 1; j >= 0; j--)
        {
            if (check(v[j], v[i]) && check(v[0], v[j]))
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }

            if (v[i].first - v[j].first > 1005)
                break;
        }
    }

    int mx = 0;
    rep(i, 0, n + 1) mx = max(mx, dp[i]);

    cout << mx << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
