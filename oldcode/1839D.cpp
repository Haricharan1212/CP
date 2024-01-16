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

    int dp[n + 2][n + 1] = {0};

    vi a(n + 2);
    a[0] = 0;
    a[n + 1] = 1e18;

    rep(i, 1, n + 1)
    {
        cin >> a[i];
    }

    rep(i, 0, n + 2)
    {
        rep(j, 0, n + 1)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
                continue;
            }

            if (a[i - 1] < a[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = 1e18;
            }
            if (j)
                rep(k, 0, i)
                {
                    if (a[k] < a[i])
                        dp[i][j] = min(dp[i][j], dp[k][j - 1] + i - k - 1);
                }
        }
    }

    // rep(i, 0, n + 2)
    // {
    //     rep(j, 0, n + 1)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int j = 1; j <= n; j++)
        cout << dp[n + 1][j] << " ";

    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
