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

// 0: not there

void dfs(int node, vii &adj, vii &dp, vb &vis)
{
    vis[node] = true;

    if (adj[node].size() == 1)
    {
        dp[node][0] = 0;
        dp[node][1] = 0;
        return;
    }

    dp[node][0] = 0;
    int x = 1e9;

    // vector<pi> diffs;

    for (auto child : adj[node])
    {
        if (!vis[child])
        {
            dfs(child, adj, dp, vis);
            dp[node][0] += dp[child][1];

            dp[node][1] += dp[child][1];
            x = min(x, dp[node][1] - dp[node][0]);

            //     diffs.push_back({dp[child][1] - dp[child][0], child});
        }
    }

    dp[node][1] = max(dp[node][0], dp[node][1] - x + 1);

    // sort(diffs.begin(), diffs.end(), greater<pi>());
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
    vector<bool> visited(n, false);
    vii dp(n, vi(2));

    dfs(0, adj, dp, visited);

    for (auto i : dp)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

    cout << dp[0][1] << endl;
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
