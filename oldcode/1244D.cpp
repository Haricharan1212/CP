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

void dfs(int node, vii &adj, vector<bool> &visited, vii &cols, int &cnt, vi &f)
{
    visited[node] = true;
    f[node] = cnt++;

    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            dfs(child, adj, visited, cols, cnt, f);
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> cols(n, vector<int>(3, 0));

    rep(j, 0, 3) rep(i, 0, n) cin >> cols[i][j];

    vii adj(n);
    rep(i, 0, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    rep(i, 0, n) if (adj[i].size() > 2)
    {
        cout << -1 << endl;
        return;
    }

    int x1 = -1, x2 = -1;
    rep(i, 0, n)
    {
        if (adj[i].size() == 1)
        {
            if (x1 == -1)
                x1 = i;
            else
                x2 = i;
        }
    }

    vector<bool> visited(n, false);
    vi f(n);
    int cnt = 0;
    dfs(x1, adj, visited, cols, cnt, f);

    vi ss = {0, 1, 2};

    int ans = 1e18;
    vi ans1;

    do
    {
        int sum = 0;
        rep(i, 0, n)
        {
            sum += cols[i][ss[f[i] % 3]];
        }

        if (sum < ans)
        {
            ans = sum;
            ans1 = ss;
        }

    } while (next_permutation(ss.begin(), ss.end()));

    cout << ans << endl;

    rep(i, 0, n) cout << ans1[f[i] % 3] + 1 << " ";
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
