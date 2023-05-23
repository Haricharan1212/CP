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
    int n, k;
    cin >> n >> k;

    vi a(n);
    int sum = 0;
    rep(i, 0, n)
    {
        cin >> a[i];
        sum += a[i];
    }

    sort(a.begin(), a.end());

    int ans = 1e18;

    vi start(k), end(k);

    rep(i, 0, k)
    {
        if (i == 0)
        {
            start[i] = a[0] + a[1];
            end[i] = a[n - 1];
        }
        else
        {
            start[i] = start[i - 1] + a[2 * i] + a[2 * i + 1];
            end[i] = end[i - 1] + a[n - i - 1];
        }
    }

    // for (auto i : start)
    //     cout << i << " ";
    // cout << endl;
    // for (auto i : end)
    //     cout << i << " ";
    // cout << endl;

    rep(i, 1, k)
    {
        ans = min(ans, start[i - 1] + end[k - i - 1]);
    }
    ans = min(ans, start[k - 1]);
    ans = min(ans, end[k - 1]);

    // cout << ans << endl;

    cout << sum - ans << endl;
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
