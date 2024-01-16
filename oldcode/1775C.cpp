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

// 1010, 1011, 1100, 1101, 1110, 1111
// 1000

void solve()
{
    int n, x;
    cin >> n >> x;

    bitset<64> a(n), b(x), c(0);

    int ans = 0;
    int flag = 0;

    for (int i = 61; i >= 0; i--)
    {
        if (a[i] == 0 && b[i] == 1)
        {
            cout << -1 << endl;
            return;
        }
        else if (a[i] == 1 && b[i] == 0)
        {
            if (flag == 0 && c[i + 1] == 0)
                c[i + 1] = 1, c[i] = 0, flag = 1;
            else if (flag == 0 && c[i + 1] == 1)
            {
                cout << -1 << endl;
                return;
            }
            else
                c[i] = 0;
        }
        else if (a[i] == 1 && b[i] == 1)
        {
            if (flag == 0)
                c[i] = 1;
            else
            {
                cout << -1 << endl;
                return;
            }
        }
        // cout << a[i] << " " << b[i] << ' ' << c[i] << endl;
        // cout << flag << endl;
    }

    cout << c.to_ullong() << endl;
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
