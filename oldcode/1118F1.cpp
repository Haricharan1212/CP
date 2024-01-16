// Haricharan

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define vi vector<int>
#define vii vector<vector<int>>
#define pi pair<int, int>
#define mi map<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)
#define repr(var, r, l) for (int var = r; var > l; var--)
int mod1 = 1000000007;
int mod2 = 998244353;

void dfs(vii &adj, vi &col, int &blue, int &redc, vector<bool> &visited, int node, vi &blues, vi &reds)
{
    visited[node] = true;
    if (col[node] == 1)
        reds[node]++;
    else if (col[node] == 2)
        blues[node]++;

    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            dfs(adj, col, blue, redc, visited, child, blues, reds);
            blues[node] += blues[child];
            reds[node] += reds[child];
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    int redc = 0, bluec = 0;

    vi col(n);
    rep(i, 0, n)
    {
        cin >> col[i];
        if (col[i] == 1)
            redc++;
        else if (col[i] == 2)
            bluec++;
    }

    vii adj(n);
    rep(i, 0, n - 1)
    {
        int a, b;
        cin >> a >> b;

        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n, false);
    vi blues(n, 0);
    vi reds(n, 0);
    dfs(adj, col, bluec, redc, visited, 0, blues, reds);

    int ans = 0;

    rep(i, 1, n) if ((blues[i] == bluec && reds[i] == 0) || (reds[i] == redc && blues[i] == 0)) ans++;
    cout << ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    while (tc--)
    {
        solve();
    }

    return 0;
}
