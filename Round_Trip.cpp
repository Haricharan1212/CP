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

bool flag = false;

void dfs(vii &adj, int node, vi &parent, vector<bool> &visited)
{
    // cout << node << 'n' << endl;
    // for (auto i : parent)
    //     cout << i << ' ';
    // cout << 'x' << endl;
    if (flag)
        return;

    visited[node] = true;

    for (auto child : adj[node])
    {
        if (child == parent[node])
            continue;
        if (visited[child])
        {
            int curr = node;

            vi ans;
            si done;

            while (curr != child)
            {
                ans.push_back(curr);
                done.insert(curr);
                curr = parent[curr];

                if (done.count(curr))
                    break;
            }

            ans.push_back(child);
            ans.push_back(node);

            cout << ans.size() << endl;
            for (auto i : ans)
                cout << i + 1 << ' ';
            flag = true;
            exit(0);
        }
        parent[child] = node;
        dfs(adj, child, parent, visited);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vii adj(n);
    rep(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vi parent(n, -1);
    vector<bool> visited(n, false);

    rep(j, 0, n)
    {
        if (visited[j])
            continue;
        parent[j] = -1;
        dfs(adj, j, parent, visited);

        if (flag)
            return;
    }
    cout << "IMPOSSIBLE";
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
