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

void dfs(vector<si> &adj, int node, vector<bool> &visited, int &count)
{
    visited[node] = true;
    count++;

    // cout << node << ' ';

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(adj, it, visited, count);
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<si> adj(n);
    vector<pi> edges(m);
    rep(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[i] = {a, b};
        adj[a].insert(b);
        adj[b].insert(a);
    }

    int k = sqrt(n);
    if (k * k != n || k * k + k != m)
    {
        cout << "NO" << endl;
        return;
    }

    rep(i, 0, n)
    {
        if (adj[i].size() != 2 && adj[i].size() != 4)
        {
            cout << "NO" << endl;
            return;
        }
    }

    vector<si> adjj = adj;

    rep(i, 0, m)
    {
        int a = edges[i].first, b = edges[i].second;

        if (adj[a].size() == 4 && adj[b].size() == 4)
        {
            adjj[a].erase(b);
            adjj[b].erase(a);
        }
    }

    // for (auto i : adj)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j + 1 << ' ';
    //     }
    //     cout << endl;
    // }

    vector<bool> visited(n, false);

    int cnt = 0;
    rep(i, 0, n)
    {
        if (!visited[i])
        {
            int count = 0;
            dfs(adj, i, visited, count);
            cnt++;
        }
    }

    if (cnt != 1)
    {
        cout << "NO" << endl;
        return;
    }

    visited = vector<bool>(n, false);

    int ccnt = 0;
    rep(i, 0, n)
    {
        if (!visited[i])
        {
            ccnt++;
            int count = 0;
            dfs(adjj, i, visited, count);
            if (count != k)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }

    if (ccnt != k)
    {
        cout << "NO" << endl;
        return;
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
    {
        solve();
    }

    return 0;
}
