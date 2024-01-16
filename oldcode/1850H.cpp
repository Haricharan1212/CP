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

void dfs(int node, vector<vector<pi>> &adj, vb &visited, vi &dists, int &flag)
{
    visited[node] = true;

    for (auto child : adj[node])
    {
        if (!visited[child.first])
        {
            dists[child.first] = dists[node] + child.second;
            dfs(child.first, adj, visited, dists, flag);
        }
        else
        {
            if (dists[child.first] != dists[node] + child.second)
            {
                flag = 0;
                return;
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pi>> adj(n);

    rep(i, 0, m)
    {
        int a, b, d;
        cin >> a >> b >> d;
        a--, b--;
        adj[a].push_back({b, d});
        adj[b].push_back({a, -d});
    }

    vi dists(n);
    vb visited(n, false);
    int flag = 1;
    rep(i, 0, n)
    {
        if (visited[i])
            continue;

        dfs(i, adj, visited, dists, flag);
    }

    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
