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
#define si multiset<int>
#define rep(var, l, r) for (int var = l; var < r; var++)
#define repr(var, r, l) for (int var = r; var > l; var--)
int mod1 = 1000000007;
int mod2 = 998244353;

void check(vii &adj, int node, vi &current, vector<bool> &visited, si &c)
{
    visited[node] = true;

    cout << endl;
    cout << node << ' ';

    for (auto i : adj[node])
    {
        cout << i << ' ';
        if (c.count(i) && current.size() > 2)
        {
            current.push_back(i);

            cout << current.size() << endl;

            for (auto i : current)
                cout << i << ' ';
            exit(0);
        }
        if (visited[i] == false)
        {
            current.push_back(i);
            c.insert(i);
            check(adj, i, current, visited, c);
            current.pop_back();
            c.erase(c.find(i));
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vii adj(n);
    rep(i, 0, n)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n, false);

    rep(i, 0, n)
    {
        if (visited[i] == false)
        {
            vi current;
            si c;
            check(adj, i, current, visited, c);
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
