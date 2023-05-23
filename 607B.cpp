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
    int n;
    cin >> n;

    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    vi dp(n, 1e9);

    dp[0] = 1;

    int ispalin[n][n];

    rep(i, 0, n) ispalin[i][i] = 1;

    rep(i, 0, n) rep(j, i + 1, n) ispalin[i][j] = (a[i] == a[j] && (i + 1 == j || ispalin[i + 1][j - 1]));

    // rep(i, 0, n)
    // {
    //     rep(j, 0, n) cout << ispalin[i][j] << " ";
    //     cout << endl;
    // }

    rep(i, 1, n)
    {
        rep(j, 0, i + 1)
        {
            if (ispalin[j][i])
                dp[i] = min(dp[i], dp[j - 1] + 1);
        }
    }

    for (auto i : dp)
        cout << i << ' ';
    cout << dp[n - 1] << endl;
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
