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

void dfs(vii &adj, int node, vector<bool> &visited, vi &depths, vi &parent)
{
    visited[node] = true;
    for (int child : adj[node])
    {
        if (!visited[child])
        {
            depths[child] = depths[node] + 1;
            parent[child] = node;
            dfs(adj, child, visited, depths, parent);
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

    vi depth(n, 0);
    vi parent(n, -1);
    vector<bool> visited(n, false);
    dfs(adj, 0, visited, depth, parent);

    vi order(n);
    rep(i, 0, n)
    {
        cin >> order[i];
        order[i]--;
    }

    if (order[0] != 0)
    {
        cout << "No\n";
        return;
    }

    reverse(order.begin(), order.end());

    int cdepth = depth[order[0]];
    visited = vector<bool>(n, false);

    rep(i, 0, n)
    {
        // cout << order[i] << " ";
        if (visited[order[i]])
        {
            cout << "No\n";
            return;
        }
        if (depth[order[i]] == cdepth)
        {
            visited[order[i]] = true;
            continue;
        }
        else if (depth[order[i]] == cdepth - 1)
        {
            cdepth--;
            visited[order[i]] = true;
        }
        else
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes" << endl;
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
