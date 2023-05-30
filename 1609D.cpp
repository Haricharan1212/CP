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

void check(vii &adj, vector<bool> &visited, int &num, int node)
{
    visited[node] = true;
    num++;
    for (auto i : adj[node])
    {
        if (visited[i] == false)
        {
            check(adj, visited, num, i);
        }
    }
}

void solve()
{
    int n, d;
    cin >> n >> d;

    vector<pi> a(d);
    vii adj(n);
    rep(i, 0, d)
    {
        cin >> a[i].first >> a[i].second;
        a[i].first--, a[i].second--;

        adj[a[i].first].push_back(a[i].second);
        adj[a[i].second].push_back(a[i].first);

        vector<bool> visited(n, false);

        int ans = 0;

        rep(j, 0, n)
        {
            if (visited[j] == false)
            {
                int num = 0;
                check(adj, visited, num, j);
                ans = max(ans, num);
            }
        }

        cout << ans - 1 << endl;
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
