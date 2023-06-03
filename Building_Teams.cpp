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
    rep(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vi cols(n, -1);

    vector<bool> visited(n, false);

    rep(j, 0, n)
    {
        if (visited[j])
            continue;

        cols[j] = 1;
        deque<int> dq = {j};

        rep(i, 0, n)
        {
            if (dq.size() == 0)
            {
                break;
            }
            int num = dq[0];
            dq.pop_front();

            // cout << num << endl;
            // for (auto i : cols)
            //     cout << i << ' ';
            // cout << endl;

            visited[num] = true;

            for (auto i : adj[num])
            {
                if (cols[i] == cols[num])
                {
                    cout << "IMPOSSIBLE" << endl;
                    return;
                }
                else if (cols[i] == -1)
                {
                    cols[i] = 3 - cols[num];
                    dq.push_back(i);
                }
            }
        }
    }

    for (auto i : cols)
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
