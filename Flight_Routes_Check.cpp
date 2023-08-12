// Haricharan
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define vb vector<bool>
#define pi pair<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)

void dfs(vii &adj, vb &visited, int node)
{
    visited[node] = true;
    for (auto child : adj[node])
    {
        if (!visited[child])
            dfs(adj, visited, child);
    }
}

void solve()
{

    int n, m;
    cin >> n >> m;

    vii adj(n);
    vii adjr(n);
    vb vis1(n, false), vis2(n, false);

    rep(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adjr[v].push_back(u);
    }

    dfs(adj, vis1, 0);
    dfs(adjr, vis2, 0);

    rep(i, 0, n)
    {
        if (!vis1[i])
        {
            cout << "NO\n";
            cout << 1 << " " << i + 1 << "\n";
            return;
        }
        if (!vis2[i])
        {
            cout << "NO\n";
            cout << i + 1 << " " << 1 << "\n";
            return;
        }
    }

    cout << "YES\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //    cin >> tc;
    while (tc--)
        solve();

    return 0;
}
