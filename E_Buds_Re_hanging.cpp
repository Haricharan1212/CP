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

void dfs (int node, vii &adj, vi &vis, int &buds, int &numleaves, int parent)
{
    vis[node] = 1;
    int child = 0;

    bool flag = true;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (adj[it].size() > 1)
                flag = false;
            
            dfs(it, adj, vis, buds, numleaves, node);
            child++;
        }
    }

    if (child == 0)
        numleaves++;
    else if (child >= 1 && flag == true && parent == 0)
        buds++;
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

    int numleaves = 0, buds = 0;

    vi vis(n, 0);
    dfs(0, adj, vis, buds, numleaves, -1);

    cout << buds << " " << numleaves << endl;

    bool flag = 0;

    for (auto it : adj[0])
    {
        if (adj[it].size() == 1)
        {
            flag = 1;
            break;
        }
    }

    cout << numleaves - buds << endl;

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