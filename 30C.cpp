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

#define float long double

struct Target
{
    float x, y, t, p;
};

void solve()
{
    int n;
    cin >> n;

    vector<Target> a(n);
    rep(i, 0, n)
    {
        cin >> a[i].x >> a[i].y >> a[i].t >> a[i].p;
    }

    float dp[n][n];

    rep(i, 0, n)
    {
        dp[0][i] = a[i].p;
    }

    sort(a.begin(), a.end(), [](Target a, Target b)
         { return a.t < b.t; });

    rep(i, 1, n)
    {
        rep(j, 0, n)
        {
            dp[i][j] = dp[i - 1][j];
            if (j == i)
                continue;

            float ff = (a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y);
            float fff = (a[j].t - a[i].t) * (a[j].t - a[i].t);
            // cout << ff << ' ' << fff << endl;
            if (ff <= fff + 1e-7 && a[i].t >= a[j].t)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i].p);
            }
        }
    }

    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    float ans = 0;

    rep(i, 0, n)
    {
        ans = max(ans, dp[n - 1][i]);
    }
    cout << setprecision(30) << ans << endl;
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
