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

void dfs(int u, vii &adj, vi &c, vb &visited)
{
    visited[u] = true;

    int cost = 0;
    for (auto v : adj[u])
    {
        if (!visited[v])
            dfs(v, adj, c, visited);
        cost += c[v];
    }

    c[u] = min(cost, c[u]);
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vi c(n);
    rep(i, 0, n) cin >> c[i];
    vb visited(n, false);

    rep(i, 0, k)
    {
        int x;
        cin >> x;
        c[x - 1] = 0;
        visited[x - 1] = true;
    }

    vii adj(n);

    rep(i, 0, n)
    {
        int m;
        cin >> m;

        if (m == 0)
            visited[i] = true;

        rep(j, 0, m)
        {
            int x;
            cin >> x;
            adj[i].push_back(x - 1);
        }
    }

    rep(i, 0, n)
    {
        if (!visited[i])
            dfs(i, adj, c, visited);
    }

    for (auto i : c)
        cout << i << ' ';
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();

    return 0;
}
