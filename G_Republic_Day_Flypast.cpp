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

int flag;

void dfs(vii &adj, int u, int p, vi &ans)
{
    if (adj[u].size() == 1)
    {
        ans[u] = 1;
    }

    for (int v : adj[u])
    {
        if (v == p)
            continue;
        dfs(adj, v, u, ans);
        ans[u] += ans[v];
    }

    // cout << u << " " << p << ans[u] << endl;

    if (ans[u] == 0)
    {
        flag = 0;
    }
    else if (ans[u] == 2)
    {
        ans[u] = 0;
        if (p != -1)
            ans[p]++;
    }
    else if (ans[u] == 1)
    {
        ans[u] = 1;
    }
    else
    {
        flag = 0;
    }

    // if (p == -1){
    //     if (ans[u] > 1) flag = 0;
    //     return;
    // }

    // if (ans[u] > 2) {
    //     flag = 0;
    // }
    // else {
    // }
}

void solve()
{
    flag = 1;
    int n;
    cin >> n;

    vii adj(n);
    rep(_, 0, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n == 2)
    {
        cout << "YES" << endl;
        return;
    }

    int start = -1;

    rep(i, 0, n) if (adj[i].size() == 1)
    {
        start = i;
        break;
    }

    vi ans(n, 0);

    dfs(adj, start, -1, ans);

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