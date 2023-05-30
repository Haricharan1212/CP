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

void check(vii &adj, vector<bool> &visited, int node, vi &subtree_count)
{
    visited[node] = true;

    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            check(adj, visited, child, subtree_count);
            subtree_count[node] += subtree_count[child];
        }
    }
}

void checkk(vii &adj, int node, int &ans, vi &subtree_count, int parent)
{
    // cout << node << ' ' << ans << endl;

    rep(i, 0, adj[node].size())
    {
        if (adj[node][i] == parent)
        {
            adj[node].erase(adj[node].begin() + i);
            break;
        }
    }

    if (adj[node].size() == 0)
    {
        return;
    }
    else if (adj[node].size() == 1)
    {

        ans += subtree_count[adj[node][0]] - 1;
    }
    else
    {
        if (subtree_count[adj[node][0]] > subtree_count[adj[node][1]])
            swap(adj[node][0], adj[node][1]);

        ans += subtree_count[adj[node][1]] - 1;
        checkk(adj, adj[node][0], ans, subtree_count, node);
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

    vi subtree_count(n, 1);
    vector<bool> visited(n, false);

    check(adj, visited, 0, subtree_count);

    int ans = 0;
    int parent = -1;
    checkk(adj, 0, ans, subtree_count, parent);

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
