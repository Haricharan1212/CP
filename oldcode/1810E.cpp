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

    vi a(n);
    set<pi> curr;
    rep(i, 0, n)
    {
        cin >> a[i];
        if (a[i] == 0)
            curr.insert({0, i});
    }

    vii adj(n);
    rep(i, 0, m)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vb visited(n, false);

    int num = 0;
    while (curr.size())
    {
        num++;
        int node = curr.begin()->second;
        curr.erase(curr.begin());
        visited[node] = true;

        cout << num << ' ' << node << ' ';

        if (num < a[node])
        {
            cout << "NO" << endl;
            return;
        }

        for (auto i : adj[node])
        {
            if (visited[i] == false)
            {
                curr.insert({a[i], i});
            }
        }
    }

    cout << "YES" << endl;
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
