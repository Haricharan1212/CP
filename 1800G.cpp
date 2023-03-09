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

void dfs(int v, int &n, vector<vector<int>> &adj, vector<int> &hash, int &flag, vector<bool> &visited)
{
    cout << v << " ";

    if (flag)
        return;
    visited[v] = true;

    vi hash_values;
    map<int, int> mm;

    for (int u : adj[v])
    {
        if (!visited[u])
            dfs(u, n, adj, hash, flag, visited);

        if (hash[u] != -1)
        {
            hash_values.push_back(hash[u]);
            mm[hash[u]]++;
        }
        else
        {
            cout << v << u << "Fail";
            return;
        }
    }

    if (adj[v].size() == 0)
    {
        hash[v] = 139;
        return;
    }
    int num = 0;

    sort(hash_values.begin(), hash_values.end());

    int ff = 0;
    for (auto i : mm)
        if (i.second % 2 == 1)
            ff++;

    if (ff >= 2)
    {
        flag = 1;
        return;
    }

    int val = 0;
    for (int i = 0; i < hash_values.size(); i++)
        val += ((1 << i) * hash_values[i] * hash_values[i]) % mod1;

    hash[v] = val;
    return;
}

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    vi hash(n, -1);

    rep(i, 0, n - 1)
    {
        int x, y;
        cin >> x >> y;

        x--;
        y--;

        adj[x].push_back(y);
    }

    int flag = 0;

    vector<bool> visited(n, false);

    dfs(0, n, adj, hash, flag, visited);

    for (auto i : hash)
        cout << i << ' ';

    if (flag == 0)
    {
        cout << "YES" << endl;
    }
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
    {
        solve();
    }

    return 0;
}
