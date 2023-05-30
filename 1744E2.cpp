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

bool check(int a, int b, int c, int d, int xx, int yy)
{
    int x = (a / xx + 1) * xx;
    int y = (b / yy + 1) * yy;

    if (x <= c && y <= d)
    {
        cout << x << " " << y << endl;
        return true;
    }

    return false;
}

void solve()
{

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    si diva;
    si divb;
    rep(i, 1, 1e5 + 5)
    {
        if (a % i == 0)
        {
            diva.insert(i);
            diva.insert(a / i);
        }
        if (b % i == 0)
        {
            divb.insert(i);
            divb.insert(b / i);
        }
    }

    for (auto i : diva)
        for (auto j : divb)
        {
            int xx = i * j;
            int yy = (a * b) / xx;

            if (check(a, b, c, d, xx, yy))
                return;
        }

    cout << "-1 -1" << endl;
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
