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

void dfs(vii &adj, int node, vi &a, vi &b, int &sum, vi &bs, vi &ans, vector<bool> &visited, int bsum)
{
    // cout << node << ' ' << sum << endl;
    // for (auto i : bs)
    //     cout << i << ' ';
    // cout << 'h' << endl;
    visited[node] = true;
    ans[node] = (upper_bound(bs.begin(), bs.end(), sum) - bs.begin()) - 1;

    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            sum += a[child];
            bsum += b[child];
            bs.push_back(bsum);
            dfs(adj, child, a, b, sum, bs, ans, visited, bsum);
            bs.pop_back();
            bsum -= b[child];
            sum -= a[child];
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    vii adj(n);
    vi a(n, 0), b(n, 0);
    rep(i, 1, n)
    {
        int x;
        cin >> x >> a[i] >> b[i];
        x--;

        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    int sum = 0, bsum = 0;
    vi bs = {0};

    vector<bool> visited(n, false);
    vi ans(n, 0);

    dfs(adj, 0, a, b, sum, bs, ans, visited, bsum);

    rep(i, 1, n)
    {
        cout << ans[i] << ' ';
    }
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
