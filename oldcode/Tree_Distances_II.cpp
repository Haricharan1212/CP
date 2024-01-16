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

void check(vii &adj, int n, vi &dist, vector<bool> &vis, vi &count)
{
    vis[n] = true;
    count[n] = 1;
    for (auto i : adj[n])
    {
        if (!vis[i])
        {
            dist[i] = dist[n] + 1;
            check(adj, i, dist, vis, count);
            count[n] += count[i];
        }
    }

    return;
}

void checkk(vii &adj, int n, vector<bool> &vis, vi &count, vi &ans)
{
    vis[n] = true;

    for (auto i : adj[n])
    {
        if (!vis[i])
        {
            ans[i] = ans[n] - count[i] + adj.size() - count[i];
            checkk(adj, i, vis, count, ans);
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

    vi dist(n), count(n), ans(n);
    vector<bool> vis(n, false);

    dist[0] = 0;
    check(adj, 0, dist, vis, count);

    int sums = 0;
    rep(i, 0, n)
    {
        sums += dist[i];
    }

    vis = vector<bool>(n, false);
    ans[0] = sums;
    checkk(adj, 0, vis, count, ans);

    for (auto i : ans)
        cout << i << ' ';
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
