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

void check(vector<si> &adj, vb &visited, int node, int &ans, vi &subtree_size)
{
    visited[node] = true;

    // cout << node << " " << subtree_size[node] << endl;

    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            check(adj, visited, child, ans, subtree_size);
            subtree_size[node] += subtree_size[child];
        }
    }

    if (subtree_size[node] % 2 == 0)
    {
        subtree_size[node] = 0;
        ans++;
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<si> adj(n);

    if (n % 2 == 1)
    {
        cout << 0 << endl;
        return;
    }

    rep(i, 0, n - 1)
    {
        int a, b;
        cin >> a >> b;
        adj[a - 1].insert(b - 1);
        adj[b - 1].insert(a - 1);
    }

    vb visited(n, false);
    int ans = 0;
    vi subtree_size(n, 1);

    check(adj, visited, 0, ans, subtree_size);

    if (subtree_size[0] != 0)
        ans = -1;

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
