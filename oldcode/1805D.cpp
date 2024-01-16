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

void dfs(int node, vii &adj, vi &dists, vector<bool> &visited)
{
    visited[node] = true;

    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            dists[child] = dists[node] + 1;
            dfs(child, adj, dists, visited);
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    vii adj(n);
    rep(i, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi dists(n, 0);
    vector<bool> visited(n, false);

    dfs(0, adj, dists, visited);
    int iindex = -1;
    int mx = -1;
    rep(i, 0, n)
    {
        if (dists[i] > mx)
        {
            mx = dists[i];
            iindex = i;
        }
    }

    vi dists1(n, 0);
    visited.assign(n, false);
    dfs(iindex, adj, dists1, visited);

    mx = -1;
    int iiindex = -1;

    rep(i, 0, n)
    {
        if (dists1[i] > mx)
        {
            mx = dists1[i];
            iiindex = i;
        }
    }

    vi dists2(n, 0);
    visited.assign(n, false);
    dfs(iiindex, adj, dists2, visited);

    vi f;

    rep(i, 0, n)
    {
        f.push_back(max(dists1[i], dists2[i]));
    }

    // for (auto i : f)
    //     cout << i << ' ';

    map<int, int> m;

    rep(i, 0, n)
    {
        m[f[i]]++;
    }

    // for (auto i : m)
    //     cout << i.first << ' ' << i.second << '\n';

    int current = 0;
    rep(i, 1, n + 1)
    {
        cout << min(n, current + 1) << " ";
        current += m[i];
    }
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
