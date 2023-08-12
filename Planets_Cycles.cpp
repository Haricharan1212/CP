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

void dfs(vi &adj, vb &vis, int node, int &cnt, si &viss)
{
    cout << node << ' ';
    vis[node] = true;
    cnt++;
    viss.insert(node);

    int child = adj[node];
    if (!vis[child])
        dfs(adj, vis, child, cnt, viss);
}

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
        a[i]--;
    }

    vb vis(n, false);
    vb ans(n);

    rep(i, 0, n)
    {
        if (vis[i])
            continue;
        set<int> viss;

        int cnt = 0;
        dfs(a, vis, i, cnt, viss);

        cout << cnt << 'c';

        for (auto j : viss)
            ans[j] = cnt;
    }

    for (auto i : ans)
        cout << i + 1 << ' ';
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
