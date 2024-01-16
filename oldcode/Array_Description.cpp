// Haricharan

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll;

// For ordered Tree
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define vi vector<int>
#define vii vector<vector<int>>

int mod = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    vector<vector<ll>> dp(n, vector<ll>(m, 0));
    if (a[0] == -1)
        dp[0] = vector<ll>(m, 1);
    else
        dp[0][a[0]]++;

    for (int i = 1; i < n; i++)
    {
        if (a[i] == -1)
            for (int j = 0; j < m; j++)
            {
                dp[i][j] = ((j != m - 1) ? dp[i - 1][j + 1] : 0) + dp[i - 1][j] + (j != 0 ? dp[i - 1][j - 1] : 0);
                dp[i][j] %= mod;
            }
        else
        {
            int j = a[i];
            dp[i][j] = ((j != m - 1) ? dp[i - 1][j + 1] : 0) + dp[i - 1][j] + (j != 0 ? dp[i - 1][j - 1] : 0);
            dp[i][j] %= mod;
        }
    }
    ll ans = 0;
    for (auto i : dp[n - 1])
        ans += i, ans %= mod;

    // for (auto i : dp)
    //     for (auto j : i)
    //         cout << j << ' ';

    cout << ans << endl;
}

int main()
{
    fio;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //   cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
