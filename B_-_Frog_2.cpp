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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i + 1];

    vector<ll> dp(1e5 + 5, 1e9);
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < min(i, k + 1); j++)
            dp[i] = min(dp[i - j] + abs(a[i] - a[i - j]), dp[i]);
    }
    cout << dp[n];
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
