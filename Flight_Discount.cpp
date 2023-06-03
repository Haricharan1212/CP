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

void dijikstra(vii &adj, int start, vi &dists, map<pi, int> &mm, int end)
{
    int n = adj.size();
    priority_queue<pi> q;

    q.push({0, start});
    vector<bool> visited(n, false);
    dists[start] = 0;

    while (!q.empty())
    {
        int num = (q.top()).second;
        q.pop();

        if (num == end)
            return;

        visited[num] = true;
        for (auto i : adj[num])
        {
            if (visited[i])
                continue;
            if (dists[num] + mm[{num, i}] < dists[i])
            {
                dists[i] = dists[num] + mm[{num, i}];
                q.push({dists[i], i});
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    map<pi, int> mm, mmm;
    vii adj(n), adjj(n);
    rep(i, 0, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        mm[{a, b}] = c;
        adj[a].push_back(b);
        adjj[b].push_back(a);
        mmm[{b, a}] = c;
    }

    vi distsa(n, 1e18);
    dijikstra(adj, 0, distsa, mm, n - 1);

    // for (auto i : distsa)
    //     cout << i << ' ';

    vi distsb(n, 1e18);

    dijikstra(adjj, n - 1, distsb, mmm, 0);

    // for (auto i : distsb)
    //     cout << i << ' ';

    int ans = 1e18;

    for (auto i : mm)
    {
        ans = min(ans, distsa[i.first.first] + i.second / 2 + distsb[i.first.second]);
    }

    cout << ans << endl;
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
