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
    int n, x, y;
    cin >> n >> x >> y;

    vi F(45);
    F[0] = 1, F[1] = 1;

    rep(i, 2, 45) F[i] = F[i - 1] + F[i - 2];

    for (int i = 44; i >= 0; i--)
    {
        if ((n - i) % 2 == 1)
        {
            if (x >= F[i])
                x -= F[i];
        }
        else
        {
            if (y >= F[i])
                y -= F[i];
        }
    }

    cout << x << ' ' << y << endl;

    // if (n % 2 == 1 && x == 1 && (y == 1 || y == 2))
    //     cout << "YES" << endl;
    // else if (n % 2 == 0 && (x == 1 || x == 2) && y == 1)
    //     cout << "YES" << endl;
    if (x == 0 && (y == 0 || y == 1))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
