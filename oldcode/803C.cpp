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

#define int unsigned long long int
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
    int n, k;
    cin >> n >> k;

    int ss = (k * (k + 1)) / 2;

    if (k > 1e9)
    {
        cout << -1 << endl;
        return;
    }

    rep(i, 1, sqrt(n) + 1)
    {
        int num = n / (i);

        if (n % num)
            continue;

        if (num * ss <= n && (n - num * (ss - k)) % num == 0)
        {
            int nn = n;

            rep(j, 1, k)
            {
                int f = num * j;
                nn -= f;
                cout << f << ' ';
            }
            cout << nn << ' ';
            return;
        }
    }
    for (int i = sqrt(n); i >= 1; i--)
    {
        int num = i;

        if (n % num)
            continue;

        if (num * ss <= n)
        {
            int nn = n;

            rep(j, 1, k)
            {
                int f = num * j;
                nn -= f;
                cout << f << ' ';
            }
            cout << nn << ' ';
            return;
        }
    }
    cout << -1 << endl;
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
