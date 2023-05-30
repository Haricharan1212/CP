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

void dfs(vii &adj, int node, vi &subtree_size, vector<bool> &visited)
{
    // cout << node << endl;
    visited[node] = true;
    subtree_size[node] = 1;

    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            dfs(adj, child, subtree_size, visited);
            subtree_size[node] += subtree_size[child];
        }
    }
    return;
}

void check(vii &adj, int &centroid, vi &subtree_size, vector<bool> &visited)
{
    int n = adj.size();
    visited[centroid] = true;

    for (auto child : adj[centroid])
    {
        if (!visited[child])
        {
            if (subtree_size[child] > n / 2)
            {
                centroid = child;
                check(adj, centroid, subtree_size, visited);
            }
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
        int a, b;
        cin >> a >> b;
        a--, b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vi subtree_size(n, 0);
    vector<bool> visited(n, false);

    dfs(adj, 0, subtree_size, visited);

    // rep(i, 0, n) cout << subtree_size[i] << " ";

    int centroid = 0;

    visited = vector<bool>(n, false);
    check(adj, centroid, subtree_size, visited);

    cout << centroid + 1 << endl;
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
