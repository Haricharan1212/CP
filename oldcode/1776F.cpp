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

void solve()
{
    int n, m;
    cin >> n >> m;

    vii adj(n);

    vector<pi> edges(m);
    rep(i, 0, m)
    {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;

        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }

    if (m == (n * (n - 1)) / 2)
    {
        int ind = 1;

        vi ans(m, -1);
        int cnt = 2;
        rep(i, 0, m)
        {
            if (edges[i].first == ind || edges[i].second == ind)
                ans[i] = min(3LL, cnt++);
            else
                ans[i] = 1;
        }

        cout << 3 << endl;

        for (auto i : ans)
            cout << i << ' ';
        cout << endl;

        return;
    }

    int ind = 0;

    while (adj[ind].size() == n - 1)
        ind++;

    vi ans(m, -1);

    rep(i, 0, m)
    {
        if (edges[i].first == ind || edges[i].second == ind)
            ans[i] = 2;
        else
            ans[i] = 1;
    }

    cout << 2 << endl;

    for (auto i : ans)
        cout << i << ' ';

    cout << endl;
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
