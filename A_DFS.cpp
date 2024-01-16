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

void dfs (int u, vii &adj, vector <pi> &edges, vb &vis){

    vis[u] = true;
    cout << u + 1 << " ";

    for (auto v: adj[u]){

        if (!vis[v]){
            dfs (v, adj, edges, vis);
        }

    }
}

void solve()
{
    int n, e;
    cin >> n >> e;

    vector <pi> edges(e);
    vii adj(n);

    rep (i, 0, e){
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);    
    }

    rep (i, 0, n) sort(adj[i].begin(), adj[i].end());

    vector <bool> vis(n, false);

    dfs (0, adj, edges, vis);

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