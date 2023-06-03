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

void showq(queue<int> gq)
{
    queue<int> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
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
    vector<bool> visited(n, false);
    vi parent(n, -1);

    queue<int> q;
    q.push(0);
    visited[0] = true;
    rep(i, 0, n)
    {
        if (q.size() == 0)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
        int num = q.front();
        q.pop();

        for (auto i : adj[num])
        {
            if (!visited[i])
            {
                visited[i] = true;

                q.push(i);
                parent[i] = num;
            }
        }
        // cout << num << 'x';

        // showq(q);
    }

    vi ff;

    int curr = n - 1;

    while (curr != 0)
    {
        ff.push_back(curr);
        curr = parent[curr];

        if (curr == -1)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    ff.push_back(0);

    reverse(ff.begin(), ff.end());

    cout << ff.size() << endl;
    for (auto i : ff)
        cout << i + 1 << ' ';
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
