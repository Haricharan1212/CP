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

set<int> done;

struct node
{
    vi adj;
    set<int> children;
    int imp = 0;
    int heavyson;
    int sonsize = 0;
    int a;
};

void build_subtree_sum(int u, vector<node> &nodes)
{
    if (done.count(u))
        return;

    done.insert(u);

    for (auto v : nodes[u].adj)
    {
        if (done.count(v))
            continue;

        nodes[u].children.insert(v);
        build_subtree_sum(v, nodes);
    }

    sort(nodes[u].children.begin(), nodes[u].children.end(), [&](int a, int b)
         { return (nodes[a].sonsize > nodes[b].sonsize) || (a < b); });

    int maxsize = 0;
    nodes[u].imp = nodes[u].a;
    for (auto v : nodes[u].children)
    {
        nodes[u].imp += nodes[v].imp;
        nodes[u].sonsize += nodes[v].sonsize;
    }
    nodes[u].sonsize += 1;
}

void solve()
{
    done.clear();

    int n, m;
    cin >> n >> m;

    vector<node> nodes(n);

    rep(i, 0, n) cin >> nodes[i].a;

    rep(i, 0, n - 1)
    {
        int a, b;
        cin >> a >> b;

        a--, b--;

        nodes[a].adj.push_back(b);
        nodes[b].adj.push_back(a);
    }

    build_subtree_sum(0, nodes);

    rep(i, 0, n)
    {
        // cout << nodes[i].imp << " " << nodes[i].heavyson << " " << nodes[i].sonsize << endl;
        // for (auto j : nodes[i].children)
        //     cout << j << " ";
        // cout << endl;
    }

    rep(i, 0, m)
    {
        int x;
        cin >> x;

        if (x == 1)
        {
            int f;
            cin >> f;
            f--;
            cout << nodes[f].imp << endl;
        }
        else
        {
            int f;
            cin >> f;

            f--;
        }
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
