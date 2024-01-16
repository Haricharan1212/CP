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
    int R, G, B;
    cin >> R >> G >> B;

    int dp[R + 1][G + 1][B + 1];

    vi r(R + 1, 0), g(G + 1, 0), b(B + 1, 0);

    rep(i, 0, R)
    {
        cin >> r[i + 1];
    }
    rep(i, 0, G)
    {
        cin >> g[i + 1];
    }
    rep(i, 0, B)
    {
        cin >> b[i + 1];
    }

    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());

    rep(i, 0, R + 1) rep(j, 0, G + 1) rep(k, 0, B + 1)
    {
        if ((i == 0 && j == 0) || (j == 0 && k == 0) || (i == 0 && k == 0))
            dp[i][j][k] = 0;
    }

    rep(i, 0, R + 1) rep(j, 0, G + 1) rep(k, 0, B + 1)
    {
        if ((i == 0 && j == 0) || (j == 0 && k == 0) || (i == 0 && k == 0))
            dp[i][j][k] = 0;
        else if (k == 0)
            dp[i][j][k] = dp[i - 1][j - 1][k] + r[i] * g[j];
        else if (j == 0)
            dp[i][j][k] = dp[i - 1][j][k - 1] + r[i] * b[k];
        else if (i == 0)
            dp[i][j][k] = dp[i][j - 1][k - 1] + g[j] * b[k];
        else
            dp[i][j][k] = max(dp[i - 1][j - 1][k] + r[i] * g[j], max(dp[i - 1][j][k - 1] + r[i] * b[k], dp[i][j - 1][k - 1] + g[j] * b[k]));
    }

    // rep(i, 0, R + 1) rep(j, 0, G + 1) rep(k, 0, B + 1)
    // {
    //     cout << dp[i][j][k] << " ";
    // }

    cout << dp[R][G][B] << "\n";
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
