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

void solve()
{

    int n, m;
    cin >> n >> m;

    vii adj(n);
    vi dist(n, 0);

    rep(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    set<pi, greater<pi>> s;
    dist[0] = 1;

    rep(i, 0, n)
    {
        s.insert({dist[i], i});
    }

    vb vis(n, false);

    rep(i, 0, n - 1)
    {
        if (s.size() == 0)
            break;

        int num = (*s.begin()).second;

        if (vis[num])
            continue;

        vis[num] = true;

        cout << num << 'x';
        s.erase(s.begin());

        for (auto child : adj[num])
        {
            s.erase(s.find({dist[child], child}));
            dist[child] = max(dist[child], dist[num] + 1);
            s.insert({dist[child], child});
        }
    }

    for (auto i : dist)
    {
        cout << i << ' ';
    }

    int cnt = dist[n];
    int num = 0;
    cout << cnt << endl;
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
