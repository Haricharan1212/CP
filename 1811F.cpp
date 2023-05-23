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

int merge(int *parent, int x)
{
    if (parent[x] == x)
        return x;
    return merge(parent, parent[x]);
}

int connectedcomponentss(int n, vector<vector<int>> &edges, int k, int flag)
{
    int parent[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    for (auto x : edges)
    {
        parent[merge(parent, x[0])] = merge(parent, x[1]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (parent[i] == i);
    }
    for (int i = 0; i < n; i++)
    {
        parent[i] = merge(parent, parent[i]);
    }
    map<int, list<int>> m;
    for (int i = 0; i < n; i++)
    {
        m[parent[i]].push_back(i);
    }

    int count = 0;

    for (auto it = m.begin(); it != m.end(); it++)
    {
        list<int> l = it->second;
        // for (auto x : l)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;

        if (l.size() != k && l.size() != 1)
        {
            cout << "NO" << endl;
            return -1;
        }
        if (l.size() == k)
            count++;
    }

    if ((count != 1))
    {
        cout << "NO" << endl;
        return -1;
    }
    return ans;
}

int connectedcomponents(int n, vector<vector<int>> &edges, int k, int flag)
{
    int parent[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    for (auto x : edges)
    {
        parent[merge(parent, x[0])] = merge(parent, x[1]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (parent[i] == i);
    }
    for (int i = 0; i < n; i++)
    {
        parent[i] = merge(parent, parent[i]);
    }
    map<int, list<int>> m;
    for (int i = 0; i < n; i++)
    {
        m[parent[i]].push_back(i);
    }

    int count = 0;

    for (auto it = m.begin(); it != m.end(); it++)
    {
        list<int> l = it->second;
        // for (auto x : l)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;

        if (l.size() != k && l.size() != 1)
        {
            cout << "NO" << endl;
            return -1;
        }
        if (l.size() == k)
            count++;
    }

    if ((count != k + 1))
    {
        cout << "NO" << endl;
        return -1;
    }
    return ans;
}

void solve()
{
    // string t;
    // cin >> t;

    int n, m;
    cin >> n >> m;

    vi adj[n];
    vector<vi> v, edges, vv;

    rep(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        if (a > b)
            swap(a, b);

        adj[a].push_back(b);
        adj[b].push_back(a);
        edges.push_back({a, b});
    }

    int k = sqrtl(n);

    if (n != k * k || (m != (k * k + k)))
    {
        cout << "NO" << endl;

        return;
    }

    rep(i, 0, n)
    {
        if (adj[i].size() != 4 && adj[i].size() != 2)
        {
            cout << "NO" << endl;
            return;
        }
    }

    rep(i, 0, m)
    {
        // cout << adj[edges[i][0]].size() << " " << adj[edges[i][1]].size() << endl;
        if (adj[edges[i][0]].size() == 2 && adj[edges[i][1]].size() == 2)
        {
            v.push_back(edges[i]);
            // s.insert(edges[i][0]);
            // s.insert(edges[i][1]);
        }
        else if (adj[edges[i][0]].size() == 4 && adj[edges[i][1]].size() == 4)
        {
            vv.push_back(edges[i]);
        }
    }

    rep(i, 0, v.size())
    {
        cout << v[i][0] << " " << v[i][1] << endl;
    }

    if (connectedcomponents(n, v, k - 1, 0) == -1)
    {
        return;
    }

    rep(i, 0, vv.size())
    {
        cout << vv[i][0] << " " << vv[i][1] << endl;
    }

    if (connectedcomponentss(n, vv, k, 1) == -1)
    {
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
