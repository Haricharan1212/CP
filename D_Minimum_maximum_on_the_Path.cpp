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

bool check(int n, vector<pair<int, pi>> &edges, int mid, int d, bool flag)
{
    vii adj(n);

    vii revadj(n);

    for (auto i : edges)
    {
        if (i.first <= mid)
        {
            int u = i.second.first;
            int v = i.second.second;

            adj[u].push_back(v);
            revadj[v].push_back(u);
        }
    }

    // dijikstra

    vi dist(n, 1e18);
    dist[0] = 0;

    priority_queue<pi, vector<pi>, greater<pi>> pq;

    pq.push({0, 0});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;

        pq.pop();

        for (auto v : adj[u])
        {
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                pq.push({dist[v], v});
            }
        }
    }

    if (flag)
    {
        // print the path
        vi path;
        int u = n - 1;
        path.push_back(u);

        while (u != 0)
        {
            for (auto v : revadj[u])
            {
                if (dist[v] == dist[u] - 1)
                {
                    path.push_back(v);
                    u = v;
                    break;
                }
            }
        }

        cout << path.size() - 1 << endl;

        reverse(path.begin(), path.end());

        for (auto i : path)
            cout << i + 1 << " ";
        cout << endl;
    }

    return dist[n - 1] <= d;
}

void solve()
{
    int n, m, d;
    cin >> n >> m >> d;

    vector<pair<int, pi>> edges(m);

    rep(i, 0, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        edges[i] = {w, {u, v}};
    }

    int l = 0;
    int r = 1e9 + 1;

    // cout << check(n, edges, 1e9, d, false) << endl;

    while (l < r)    
    {
        int mid = (l + r) / 2;

        if (check(n, edges, mid, d, false))
        {
            r = mid;
        }
        else
            l = mid + 1;
    }

    if (l != (int)(1e9 + 1))
        check(n, edges, l, d, true);
    else
        cout << -1 << endl;

    // cout << l << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();

    return 0;
}