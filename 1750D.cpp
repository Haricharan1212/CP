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

int mod = 998244353;

void solve()
{
    int n, m;
    cin >> n >> m;

    ll ans = 1;

    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> dp(n);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp[i] = 1;
        }
        else
        {
            if (a[i] == a[i - 1])
                dp[i] = dp[i - 1] * (m / a[i]);
            else if (a[i - 1] % a[i] != 0)
                dp[i] = 0;
            else
            {
                dp[i] = dp[i - 1] * (m / a[i] - m / a[i - 1]);
            }
        }
        dp[i] %= mod;
    }

    cout << dp[n - 1] << endl;
}

int main()
{
    fio;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
