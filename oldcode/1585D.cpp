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

void dfs(vii &adj, vector<bool> &visited, int node, int &f)
{
    f++;
    visited[node] = true;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(adj, visited, i, f);
        }
    }
    return;
}

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    set<int> s;
    rep(i, 0, n)
    {
        cin >> a[i];
        s.insert(a[i]);
    }

    if (s.size() != n)
    {
        cout << "YES\n";
        return;
    }

    vector<pi> b(n);
    rep(i, 0, n)
    {
        b[i] = {a[i] - 1, i};
    }
    sort(b.begin(), b.end());

    vii adj(n);

    rep(i, 0, n)
    {
        adj[b[i].first].push_back(b[i].second);
        adj[b[i].second].push_back(b[i].first);
    }

    vector<bool> visited(n, false);

    int ans = 0;
    rep(i, 0, n)
    {
        int f = 0;
        if (visited[i] == false)
        {
            dfs(adj, visited, i, f);
            ans += f - 1;
        }
    }

    if (ans % 2 == 0)
        cout << "YES" << endl;
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
