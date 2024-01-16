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

void check(int node, vii &adj, vi &arr, vb &visited)
{
    visited[node] = true;
    int ans = 0;

    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            check(child, adj, arr, visited);
            ans += arr[child];
        }
    }

    if (adj[node].size() == 1 && node != 0)
        arr[node] = 1;
    else
        arr[node] = ans;
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
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vi arr(n, 0);
    vb visited(n, false);
    check(0, adj, arr, visited);

    // for (auto i : arr)
    //     cout << i << ' ';

    int q;
    cin >> q;

    rep(i, 0, q)
    {
        int x, y;
        cin >> x >> y;
        cout << arr[x - 1] * arr[y - 1] << endl;
    }
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
