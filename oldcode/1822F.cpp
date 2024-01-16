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

void dfs(int node, vii &adj, vi &dist, vb &vis)
{

    vis[node] = true;

    for (auto child : adj[node])
    {
        if (!vis[child])
        {
            dist[child] = dist[node] + 1;
            dfs(child, adj, dist, vis);
        }
    }
}

void solve()
{
    int n, k, c;
    cin >> n >> k >> c;

    vii adj(n);

    rep(i, 0, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vi dist(n, 0);
    vb vis(n, false);

    dfs(0, adj, dist, vis);
    int mx = -1;
    int mx_idx = -1;

    rep(i, 0, n)
    {
        if (dist[i] > mx)
        {
            mx = dist[i];
            mx_idx = i;
        }
    }

    vis = vb(n, false);
    vi dist2(n, 0);

    dfs(mx_idx, adj, dist2, vis);
    mx = -1;
    int mx_iidx = -1;
    rep(i, 0, n)
    {
        if (dist2[i] > mx)
        {
            mx = dist2[i];
            mx_iidx = i;
        }
    }

    vi dist3(n, 0);
    vis = vb(n, false);

    dfs(mx_iidx, adj, dist3, vis);

    int ans = 0;
    rep(i, 0, n)
    {
        // cout << dist[i] << " " << dist2[i] << " " << dist3[i] << endl;
        // cout << ans << endl;
        ans = max(ans, max(dist2[i], dist3[i]) * k - c * dist[i]);
    }
    cout << ans << endl;
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
