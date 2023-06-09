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

void check(vii &adj, vb &vis, int i, bool &flag, int parent)
{
    vis[i] = true;

    for (auto &j : adj[i])
    {
        if (j == parent)
            continue;
        if (vis[j])
            flag = true;
        else
            check(adj, vis, j, flag, i);
    }
}

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    vii adj(n);
    rep(i, 0, n)
    {
        cin >> a[i];
        a[i]--;
        adj[i].push_back(a[i]);
    }

    vb vis(n, false);
    int c = 0, b = 0;
    rep(i, 0, n)
    {
        if (vis[i])
            continue;
        bool flag = false;
        check(adj, vis, i, flag, -1);

        if (flag)
            c++;
        else
            b++;
    }
    cout << c + min(1LL, b) << ' ' << c + b << endl;
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
