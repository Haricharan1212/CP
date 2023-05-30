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

vector<int> factorials(int n, int mod1)
{
    vector<int> fact(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    return fact;
}

vi facts;

void solve()
{
    int n, k;
    cin >> n >> k;

    int ncnby2 = (facts[n] * modexp(facts[n / 2], mod1 - 2, mod1)) % mod1;
    ncnby2 = (ncnby2 * modexp(facts[n / 2], mod1 - 2, mod1)) % mod1;

    if (n % 2 == 0)
    {
        int ans = 1;

        int current = 1;
        int eq = 1;

        rep(i, 0, k)
        {
            ans += modexp(n, k - (i + 1), mod1);
            current *= (n - eq);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;

    facts = factorials(200005, mod1);

    while (tc--)
    {
        solve();
    }

    return 0;
}
