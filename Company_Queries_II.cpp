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

int get_k(vii &arr, int node, int k)
{
    int ans = node;
    int i = 0;
    while (k)
    {
        if (k & 1)
        {
            ans = arr[ans][i];
            if (ans == -1)
                break;
        }
        k = k >> 1;
        i++;
    }

    return ans;
}

void dfs(vii &adj, vi &depths, int node, vector<bool> &visited)
{

    visited[node] = true;

    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            depths[child] = depths[node] + 1;
            dfs(adj, depths, child, visited);
        }
    }
}

int get_lca(vii &arr, vi &depths, int a, int b)
{
    int lg = 21;
    if (depths[a] < depths[b])
        swap(a, b);

    a = get_k(arr, a, depths[a] - depths[b]);

    if (a == b)
    {
        return a;
    }

    for (int i = lg - 1; i >= 0; i--)
    {
        if (arr[a][i] != arr[b][i])
        {
            a = arr[a][i];
            b = arr[b][i];
        }
    }

    return arr[a][0];
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vi parent(n, -1);

    vii adj(n);

    rep(i, 1, n)
    {
        cin >> parent[i];
        parent[i]--;

        adj[parent[i]].push_back(i);
        adj[i].push_back(parent[i]);
    }

    int lg = 21;
    vii arr(n, vi(lg, -1));
    rep(i, 0, n)
        arr[i][0] = parent[i];
    rep(j, 1, lg)
    {
        rep(i, 0, n)
        {
            if (arr[i][j - 1] != -1)
                arr[i][j] = arr[arr[i][j - 1]][j - 1];
            else
                arr[i][j] = -1;
        }
    }

    vi depths(n, 0);
    vector<bool> visited(n, false);
    dfs(adj, depths, 0, visited);

    while (q--)
    {
        int a, b;
        cin >> a >> b;

        a--, b--;

        cout << get_lca(arr, depths, a, b) + 1 << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}