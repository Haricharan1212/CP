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
    int k, a, b;
    cin >> k >> a >> b;
    a--, b--;
    vii adj(9);

    int aa[3][3], bb[3][3];

    rep(i, 0, 3)
    {
        rep(j, 0, 3)
        {
            cin >> aa[i][j];
            aa[i][j]--;
        }
    }

    rep(i, 0, 3)
    {
        rep(j, 0, 3)
        {
            cin >> bb[i][j];
            bb[i][j]--;
        }
    }

    rep(i, 0, 3)
        rep(j, 0, 3)
    {
        adj[3 * i + j].push_back(3 * aa[i][j] + bb[i][j]);
    }

    int start = 3 * a + b;
    int current = start;

    vi f = {current};

    while (current != start)
    {
        current = adj[current][0];
        f.push_back(current);
    }

    // for (auto i : f)
    //     cout << i << ' ';

    int sz = f.size();
    int pts = 0;

    vi ptsa(f.size()), ptsb(f.size());

    rep(i, 0, sz)
    {
        int x = (f[i] / 3) - (f[i] % 3);
        if (x == 1 || x == -2)
            ptsa[i] = 1, ptsb[i] = 0;
        else if (x == 0)
            ptsa[i] = 0, ptsb[i] = 0;
        else
            ptsa[i] = 0, ptsb[i] = 1;
    }

    int ansa = 0, ansb = 0;
    rep(i, 0, sz)
    {
        ansa += ptsa[i] * (k / sz);
        ansb += ptsb[i] * (k / sz);
    }
    rep(i, 0, k % sz)
    {
        ansa += ptsa[i];
        ansb += ptsb[i];
    }

    cout << ansa << " " << ansb << endl;
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
