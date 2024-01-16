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

void solve()
{
    int n, k;
    cin >> n >> k;

    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    vector<vector<pi>> dp(n, vector<pi>(k + 1));

    rep(i, 0, n)
    {
        rep(j, 0, k + 1)
        {
            if (k == 0)
            {
                dp[i][j] = {0, 0};
                continue;
            }
            else if (i == 0)
            {
                dp[i][j] = {a[i], 1};
                continue;
            }
            dp[i][k] = dp[i][k - 1];

            if (dp[i][k].second <= dp[i - 1][k].second)
            {
                dp[i][k] = max(dp[i][k], {dp[i - 1][k] + a[i], dp[i - 1][k].second + 1});
            }

            // dp[i][k] = max({dp[i - 1][k].first, 0}, {dp[i][k - 1].first, dp[i][k - 1].second + 1});
        }
    }

    cout << dp[n - 1][k].first << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
