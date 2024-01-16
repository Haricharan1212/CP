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

void dfs(int node, vector<bool> &vis, vii &adj, vi &subtree_size, vi &father, vi &imp, vector<set<pi>> &sons)
{

    visited[node] = true;

    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            father[child] = node;
            dfs(child, visited, adj, subtree_size, father, imp, sons);
            subtree_size[node] += subtree_size[child];
            sons[node].insert({-subtree_size[child], child});
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vii adj(n);
    vi imp(n);
    rep(i, 0, n) cin >> imp[i];

    rep(i, 0, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vi subtree_size(n, 0);
    vi father(n, -1);

    vector<set<pi>> sons(n);

    vector<bool> vis(n, 0);

    dfs(0, vis, adj, subtree_size, father, imp, sons);

    rep(i, 0, m)
    {

        int a, b;
        cin >> a >> b;

        if (a == 1)
        {
            cout << imp[b - 1] << "\n";
        }
        else
        {
            b--;

            if (sons[b].size() == 0)
                continue;

            int heavyson = sons[b].begin()->second;
            sons[b].erase(sons[b].begin());

            int fat = father[b];

            sons[fat].erase({-subtree_size[b], b});
            sons[fat].insert({})
        }
    }
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
