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
    int n, m, i1, j1, i2, j2;
    string d;
    cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> d;

    i1--;
    i2--;
    j1--;
    j2--;

    int count = 0;
    int bounce = 0;
    set<pair<pi, string>> s;
    while (count < 4 * n * m)
    {
        int flag = 0;

        s.insert({{i1, j1}, d});
        if (s.count({{i2, j2}, "UL"}) || s.count({{i2, j2}, "DR"}) || s.count({{i2, j2}, "DL"}) || s.count({{i2, j2}, "UR"}))
        {
            cout << bounce << endl;
            return;
        }

        count++;
        if ((d[0] == 'U' && i1 == 0) || d[0] == 'D' && i1 == n - 1)
        {
            d[0] = (d[0] == 'U') ? 'D' : 'U';
            flag++;
        }
        if (d[0] == 'U')
            i1--;
        else
            i1++;

        if ((d[1] == 'L' && j1 == 0) || d[1] == 'R' && j1 == m - 1)
        {
            d[1] = (d[1] == 'L') ? 'R' : 'L';
            flag++;
        }

        if (d[1] == 'L')
            j1--;
        else
            j1++;

        if (s.count({{i1, j1}, d}))
        {
            cout << -1 << endl;
            return;
        }

        if (flag)
            bounce++;
    }

    cout << "-1" << endl;
    return;
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
