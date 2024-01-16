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

void check(vi &a, vi &h, vii &adj, int node, vector<bool> &vis)
{
    vis[node] = true;
    int sum = 0;
    int mx = 0;
    for (auto x : adj[node])
    {
        if (vis[x])
            continue;

        check(a, h, adj, x, vis);
        sum += a[x];
        mx = max(mx, h[x]);
    }

    a[node] = max(mx + 1, sum);
    h[node] = mx + 1;
}

void solve()
{
    int n;
    cin >> n;

    vii adj(n);

    rep(i, 1, n)
    {
        int x;
        cin >> x;
        x--;

        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    vi a(n, -1);
    vector<bool> vis(n, false);
    vi h(n, -1);

    check(a, h, adj, 0, vis);

    // rep(i, 0, n)
    //         cout
    //     << a[i] << " ";

    cout << a[0] << endl;
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
