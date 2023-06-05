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

void dfs(vii &adj, int node, vi &subtree_size, vector<bool> &visited, int &cnt)
{
    // cout << node << endl;
    visited[node] = true;
    subtree_size[node] = 1;
    cnt++;

    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            dfs(adj, child, subtree_size, visited, cnt);
            subtree_size[node] += subtree_size[child];
        }
    }
    return;
}

void check(vii &adj, int &centroid, vi &subtree_size, vector<bool> &visited, int &cnt)
{
    visited[centroid] = true;

    for (auto child : adj[centroid])
    {
        if (!visited[child])
        {
            if (subtree_size[child] > (cnt - 1) / 2)
            {
                centroid = child;
                check(adj, centroid, subtree_size, visited, cnt);
            }
            else
            {
                check(adj, child, subtree_size, visited, cnt);
            }
        }
    }
}

void checkdia(vii &adj, int n, vi &dist, vector<bool> &vis)
{
    vis[n] = true;

    for (auto i : adj[n])
    {
        if (!vis[i])
        {
            dist[i] = dist[n] + 1;
            checkdia(adj, i, dist, vis);
        }
    }

    return;
}

int getdia(vii &adj)
{
    int n = adj.size();

    vi dist(n);
    vector<bool> vis(n, false);

    dist[0] = 0;
    checkdia(adj, 0, dist, vis);

    int max = 0, max_index = 0;

    rep(i, 0, n)
    {
        if (dist[i] > max)
        {
            max = dist[i];
            max_index = i;
        }
    }

    vis = vector<bool>(n, false);
    dist = vi(n);

    dist[max_index] = 0;
    checkdia(adj, max_index, dist, vis);

    max = 0;

    rep(i, 0, n)
    {
        if (dist[i] > max)
        {
            max = dist[i];
        }
    }
    return max;
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
