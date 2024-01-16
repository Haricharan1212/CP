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
    ll n;
    cin >> n;

    ll dp[n + 1] = {0};
    dp[0] = 1;

    if (n % 4 == 1 || n % 4 == 2)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        int mod = 2 * ((int)1e9 + 7);
        ll sum = (n * (n + 1)) / 4;
        ll dp[sum + 1] = {0};
        dp[0] = 1;

        for (ll i = 1; i <= n; i++)
        {
            for (ll j = sum; j >= 1; j--)
            {
                if (j >= i)
                    dp[j] += dp[j - i];
                dp[j] %= mod;
            }
        }

        cout << (dp[sum] / 2);
    }
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
