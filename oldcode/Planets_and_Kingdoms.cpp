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
    vector<int> ans(n, -1);

    rep(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adjr[v].push_back(u);
    }

    int cnt = 1;

    rep(i, 0, n)
    {
        if (vis1[i] == false)
        {
            // cout << i << ' ' << cnt << endl;
            dfs(adj, vis1, i);
            dfs(adjr, vis2, i);

            rep(i, 0, n)
            {
                if (vis1[i] && vis2[i] && ans[i] == -1)
                {
                    ans[i] = cnt;
                }
                else
                {
                    vis1[i] = false;
                    vis2[i] = false;
                }
            }

            cnt++;
        }
    }

    cout << cnt - 1 << endl;

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
        solve();

    return 0;
}
