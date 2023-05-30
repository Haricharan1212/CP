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

void check(vii &adj, int n, vi &dist, vector<bool> &vis)
{
    vis[n] = true;

    for (auto i : adj[n])
    {
        if (!vis[i])
        {
            dist[i] = dist[n] + 1;
            check(adj, i, dist, vis);
        }
    }

    return;
}

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n);

    rep(i, 0, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vi dist(n);
    vector<bool> vis(n, false);

    dist[0] = 0;
    check(adj, 0, dist, vis);

    int mx = 0, max_index = 0;

    rep(i, 0, n)
    {
        if (dist[i] > mx)
        {
            mx = dist[i];
            max_index = i;
        }
    }

    vis = vector<bool>(n, false);
    dist = vi(n);

    dist[max_index] = 0;
    check(adj, max_index, dist, vis);

    // for (auto i : dist)
    //     cout << i << ' ';

    mx = 0;
    int max_iindex = 0;

    rep(i, 0, n)
    {
        if (dist[i] > mx)
        {
            mx = dist[i];
            max_iindex = i;
        }
    }

    vis = vector<bool>(n, false);
    vi dist2(n);

    dist2[max_iindex] = 0;
    check(adj, max_iindex, dist2, vis);

    rep(i, 0, n) cout << max(dist[i], dist2[i]) << ' ';
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
