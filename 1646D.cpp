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

void dfs(int node, vii &adj, vi &cols, vector<bool> &visited)
{
    visited[node] = true;
    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            cols[child] = 1 - cols[node];
            dfs(child, adj, cols, visited);
        }
    }
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

    if (n == 2)
    {
        cout << "2 2\n1 1\n";
        return;
    }

    vi cols(n, -1);
    cols[0] = 0;
    vector<bool> vis(n, false);

    dfs(0, adj, cols, vis);

    int num = count(cols.begin(), cols.end(), 0);

    int des;
    if (num > n - num)
        des = 0;
    else
        des = 1;

    vi ans(n);

    rep(i, 0, n)
    {
        if (cols[i] == des)
            ans[i] = adj[i].size();
        else
            ans[i] = 1;
    }

    int sm = 0;

    for (auto i : ans)
        sm += i;

    cout << max(num, n - num) << ' ' << sm << endl;

    for (auto i : ans)
        cout << i << ' ';
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
