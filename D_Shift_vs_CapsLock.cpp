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
    int x, y, z;
    cin >> x >> y >> z;

    string s;
    cin >> s;

    int n = s.size();
    int dp[n + 1][2];
    dp[0][0] = 0;
    dp[0][1] = z;

    rep(i, 1, n + 1)
    {
        dp[i][0] = dp[i][1] = 1e18;
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][0] + z);
        dp[i][1] = min(dp[i - 1][0] + z, dp[i - 1][1]);

        if (s[i - 1] == 'a')
        {
            dp[i][0] += x;
            dp[i][1] += y;
        }
        else if (s[i - 1] == 'A')
        {
            dp[i][0] += y;
            dp[i][1] += x;
        }
    }

    // rep(i, 0, n + 1)
    // {
    //     cout << dp[i][0] << " " << dp[i][1] << endl;
    // }

    int ans = min(dp[n][0], dp[n][1]);

    cout << ans << endl;
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
