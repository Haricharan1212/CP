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

pi check_ans(int node, vii &adj, vector<bool> &visited)
{
    visited[node] = true;
    pi ans = {node, 0};
    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            pi temp = check_ans(child, adj, visited);
            if (temp.second + 1 > ans.second)
            {
                ans.first = temp.first;
                ans.second = temp.second + 1;
            }
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;

    vector<pi> a;
    vector<bool> visited(n, false);
    vii adj(n);

    rep(i, 0, n)
    {
        cin >> a[i].first >> a[i].second;
        adj[a[i].first].push_back(a[i].second);
        adj[a[i].second].push_back(a[i].first);
    }

    pi f = check_ans(0, adj, visited);
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
