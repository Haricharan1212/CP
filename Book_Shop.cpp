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

#define vi vector<ll>
#define vii vector<vector<ll>>

void solve()
{
    ll n, x;
    cin >> n >> x;

    vi h(n);
    vi s(n);

    for (ll i = 0; i < n; i++)
        cin >> h[i];
    for (ll i = 0; i < n; i++)
        cin >> s[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(x + 1, 0));

    for (ll i = 1; i < n + 1; i++)
        for (ll j = 1; j < x + 1; j++)
        {
            if (j >= h[i - 1])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - h[i - 1]] + s[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    cout << dp[n][x];
}

int main()
{
    fio;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
