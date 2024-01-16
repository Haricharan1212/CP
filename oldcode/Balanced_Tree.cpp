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

void check(vii &adj, vb &visited, int node, vi &dist, a)
{
    visited[node] = true;
    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            dist[child] = dist[node] + 1;
            check(adj, visited, child, dist);
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
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    vi a(n);
    int mx = 0;
    int mxnode = -1;
    rep(i, 0, n)
    {
        cin >> a[i];
        if (a[i] > mx)
        {
            mx = a[i];
            mxnode = i;
        }
    }

    rep(i, 0, n) a[i] -= mx;

    vb visited(n, false);
    vi dist(n, 0);
    check(adj, visited, mxnode, dist, a);
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
