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

    int x, y, l, r;
    cin >> x >> y >> l >> r;

    vi ff;

    // rep(i, 0, logl(1e18) / logl(x))
    //     rep(j, 0, logl(1e18) / logl(y))

    for (int i = 0; i <= logl(1e18) / logl(x); i++)
        for (int j = 0; pow(x, i) + pow(y, j) <= 1e18; j++)
        {
            int xx = powl(x, i) + powl(y, j);
            if (xx < l)
                continue;
            if (xx > r)
                break;
            // cout << i << ' ' << j << endl;

            // cout << xx << endl;
            ff.push_back(xx);
        }

    sort(ff.begin(), ff.end());

    int ans = 0;

    if (ff.size() == 0)
    {
        cout << r - l + 1 << endl;
        return;
    }

    rep(i, 0, ff.size() - 1)
    {
        // cout << ff[i] << ' ';
        if (ff[i] >= l && ff[i + 1] <= r)
            ans = max(ans, ff[i + 1] - ff[i] - 1);
    }

    ans = max(ans, ff[0] - l);
    ans = max(ans, r - ff[ff.size() - 1]);
    cout << ans << endl;
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
