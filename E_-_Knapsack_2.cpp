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

void solve()
{
    int n, W;
    cin >> n >> W;

    vector<ll> w(n), v(n);
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];

    vector<ll> dp(1e5 + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = (int)1e5; j > 0; j--)
        {
            if (j >= v[i])
            {
                if (dp[j - v[i]] != -1)
                    if (dp[j] == -1)
                        dp[j] = dp[j - v[i]] + w[i];
                    else
                        dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
            }
        }
    }
    ll ans = 0;

    // for (int i = 0; i < 20; i++)
    //     cout << dp[i] << ' ';

    for (int j = (int)1e5; j > 0; j--)
    {
        if (dp[j] != -1 && dp[j] <= W)
        {
            ans = j;
            break;
        }
    }
    cout << ans;
}

int main()
{
    fio;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
