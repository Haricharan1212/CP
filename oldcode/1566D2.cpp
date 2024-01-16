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
    int n, m;
    cin >> n >> m;

    vector<pi> a(n * m);

    rep(i, 0, n * m)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    rep(i, 0, n * m)
    {
        a[i].second *= -1;
    }

    // rep(i, 0, n * m)
    // {
    //     cout << a[i].first << " " << a[i].second << endl;
    // }

    int ar[n][m];

    rep(i, 0, n) rep(j, 0, m)
    {
        ar[i][j] = a[m * i + j].second;
    }

    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cout << ar[i][j] + 1 << " ";
        }
        cout << endl;
    }

    int ans = 0;
    rep(i, 0, n)
    {
        ordered_set s;

        rep(j, 0, m)
        {
            ans += s.order_of_key(ar[i][j]);
            s.insert(ar[i][j]);
        }
    }

    cout << ans << endl;
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
