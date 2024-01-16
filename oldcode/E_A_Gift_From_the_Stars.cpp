#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

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

void search(int node, vii &adj, vector<bool> &visited, vi &dist)
{

    visited[node] = true;

    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dist[i] = dist[node] + 1;
            search(i, adj, visited, dist);
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<pi> a(n);
    vector<vector<int>> adj(n);
    rep(i, 0, n - 1)
    {
        cin >> a[i].first >> a[i].second;

        adj[a[i].first - 1].push_back(a[i].second - 1);
        adj[a[i].second - 1].push_back(a[i].first - 1);
    }

    vi ans, dist(n);
    vector<bool> visited(n);

    int start = -1;
    rep(i, 0, n) if (adj[i].size() == 1) start = adj[i][0];

    dist[start] = 0;
    search(start, adj, visited, dist);

    rep(i, 0, n)
    {
        if (dist[i] % 3 == 0)
            ans.push_back(adj[i].size());
    }

    sort(ans.begin(), ans.end());

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