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
#define si multiset<int>
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

vector<bool> siev;

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
    vi modfact(3000);

    for (int i = 0; i < 3000; i++)
    {
        if (i == 0)
            modfact[i] = 1;
        else
            modfact[i] = (modfact[i - 1] * i) % mod2;
    }

    int n;
    cin >> n;

    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    map<int, int> m;

    for (auto i : a)
        m[i]++;

    vi prims;
    vi comps;

    for (auto i : m)
        if (siev[i.first])
            prims.push_back(i.second);
        else
            comps.push_back(i.second);

    sort(prims.begin(), prims.end());

    int f = prims.size();

    int dp[f][2] = {0};

    for (int i = 0; i < f; i++)
    {
        if (i == 0)
        {
            dp[i][0] = 1;
            dp[i][1] = 1;
        }
        else
        {
            dp[i][0] = dp[i - 1][1] + prims[i];
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;

    siev = sieve(1e6 + 5);
    while (tc--)
    {
        solve();
    }

    return 0;
}
