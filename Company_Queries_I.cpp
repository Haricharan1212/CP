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

int get_k(vii &arr, int node, int k)
{
    int ans = node;
    int i = 0;
    while (k)
    {
        if (k & 1)
        {
            ans = arr[ans][i];
            if (ans == -1)
                break;
        }
        k = k >> 1;
        i++;
    }

    return ans;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vi parent(n, -1);

    rep(i, 1, n)
    {
        cin >> parent[i];
        parent[i]--;
    }

    int lg = 21;

    vii arr(n, vi(lg, -1));

    rep(i, 0, n)
        arr[i][0] = parent[i];

    rep(j, 1, lg)
    {
        rep(i, 0, n)
        {
            if (arr[i][j - 1] != -1)
                arr[i][j] = arr[arr[i][j - 1]][j - 1];
            else
                arr[i][j] = -1;
        }
    }

    // rep(i, 0, n)
    // {
    //     rep(j, 0, 6) cout << arr[i][j] << " ";
    //     cout << endl;
    // }

    while (q--)
    {
        int node, k;
        cin >> node >> k;
        node--;

        int ans = get_k(arr, node, k);

        if (ans == -1)
            cout << "-1\n";
        else
            cout << ans + 1 << "\n";
    }
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
