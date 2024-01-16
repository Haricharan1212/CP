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

void check(vii &adj, map<pi, int> &mm, set<pi> &pq, si &done, vi &dist)
{
    pi current = *pq.begin();
    pq.erase(pq.begin());

    int node = current.second;
    done.insert(node);
    int distance = current.first;

    for (auto i : adj[node])
    {
        if (done.count(i) == 0)
            if (distance + mm[{node, i}] < dist[i])
            {
                pq.erase({dist[i], i});
                dist[i] = distance + mm[{node, i}];
                pq.insert({dist[i], i});
            }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    map<pi, int> mm;
    rep(i, 0, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        if (mm[{a, b}] == 0)
            mm[{a, b}] = c;
        else
            mm[{a, b}] = min(mm[{a, b}], c);
    }

    vii adj(n);
    for (auto i : mm)
    {
        // cout << i.first.first << ' ' << i.first.second << ' ' << i.second << '\n';
        adj[i.first.first].push_back(i.first.second);
    }

    set<pi> pq;

    vi dist(n, 0);
    rep(i, 1, n)
        dist[i] = 1e18;

    rep(i, 0, n) pq.insert({dist[i], i});
    si done;

    while (done.size() != n)
        check(adj, mm, pq, done, dist);

    for (auto i : dist)
        cout << i << ' ';
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
