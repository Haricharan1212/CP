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
    map<int, vi> m;
    map<int, int, greater<int>> dp;

    rep(i, 0, n)
    {
        int l, r;
        cin >> l >> r;
        l++;
        m[r].push_back(l);
    }

    dp[0] = 0;

    int currentmx = 0;

    for (auto i : m)
    {
        dp[i.first] = currentmx;
        for (auto j : i.second)
        {
            dp[i.first] = max(dp[i.first], dp.lower_bound(j - 1)->second + 1);
        }

        currentmx = max(currentmx, dp[i.first]);
    }

    // // for (auto i : dp)
    // // {
    // //     cout << i.first << " " << i.second << endl;
    // }

    cout << dp.begin()->second << endl;
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
