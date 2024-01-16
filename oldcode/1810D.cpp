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

int modexp(long long x, unsigned int y, int p)
{
    int res = 1;

    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

vector<bool> sieve(int n)
{
    // Time Complexity:- O(log(log(n)))

    vector<bool> is_prime(n + 1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] && 1LL * i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = 0;
        }
    }
    return is_prime;
}

void solve()
{
    int q;
    cin >> q;

    int hmin = 0, hmax = 1e9;

    rep(i, 0, q)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int a, b, n;
            cin >> a >> b >> n;

            int hming;
            if (n > 1)
                hming = max((n - 1) * a + 1 - (n - 1) * b, (n - 1) * (a) - (n - 2) * b + 1);
            else
                hming = (n - 1) * a + 1 - (n - 1) * b;
            int hmaxg = n * (a) - (n - 1) * b;

            if (hmaxg < hmin || hming > hmax)
            {
                cout << 0 << ' ';
                continue;
            }
            else
            {
                cout << 1 << ' ';
            }

            if (hming > hmin)
            {
                hmin = hming;
            }
            if (hmaxg < hmax)
            {
                hmax = hmaxg;
            }

            // cout << hmin << " " << hmax << endl;
        }
        else
        {
            int a, b;
            cin >> a >> b;

            int days1 = (hmin - a + (a - b) - 1) / (a - b) + 1;
            int days2 = (hmax - a + (a - b) - 1) / (a - b) + 1;

            // cout << days1 << ' ' << days2 << endl;

            if (days1 == days2)
                cout << max(1ll, days1) << ' ';
            else
                cout << -1 << ' ';
        }
    }
    cout << endl;
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
