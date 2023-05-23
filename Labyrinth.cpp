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

vector<pi> return_adj(vector<vector<pi>> &adj, int i, int j, int n, int m)
{
    vector<pi> ans;
    if (i > 0 && a[i - 1][j] == '.')
    {
        ans.push_back({i - 1, j});
    }
    if (i < n - 1 && a[i + 1][j] == '.')
    {
        ans.push_back({i + 1, j});
    }
    if (j > 0 && a[i][j - 1] == '.')
    {
        ans.push_back({i, j - 1});
    }
    if (j < m - 1 && a[i][j + 1] == '.')
    {
        ans.push_back({i, j + 1});
    }
    return ans;
}

void solve()
{
    set<pi> visited;
    vector<vector<pi>> adj;
    set<pi> level_set;

    int n, m;
    cin >> n >> m;

    vector<string> a(n);
    pi start, end;
    rep(i, 0, n)
    {
        cin >> a[i];

        for (auto j : a[i])
            if (j == 'A')
                start = {i, j};
            else if (j == 'B')
                end = {i, j};
    }

    level_set = {start};
    visited.insert(start);

    while (level_set.size())
    {
        set<pi> next_level_set;
        for (auto i : level_set)
        {
            if (i == end)
            {
            }

            vector<pi> adj = return_adj(adj, i.first, i.second, n, m);
            for (auto j : adj)
            {
                if (visited.find(j) == visited.end())
                {
                    visited.insert(j);
                    next_level_set.insert(j);
                }
            }
        }
        level_set = next_level_set;
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
