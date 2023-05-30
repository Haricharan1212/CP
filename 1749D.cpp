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
int mod2 = 998244353;

vector<bool> sieve(int n)
{
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= n; ++i)
        if (prime[i])
            if (i * 1ll * i <= n)
                for (int j = i * i; j <= n; j += i)
                    prime[j] = false;
    return prime;
}

int modexp(int a, int b, int m)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<bool> prime = sieve(n + 1);

    vi dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = m;

    int num = 1;

    rep(i, 2, n + 1)
    {
        dp[i] = dp[i - 1];

        if (prime[i])
        {
            num *= i;
        }

        dp[i] *= ((m / num) % mod2);
        dp[i] %= mod2;

        if (num > m)
            break;
    }

    int ans = 0;

    rep(i, 1, n + 1)
    {
        // cout << dp[i] << endl;
        ans += modexp(m, i, mod2) - dp[i];
        ans %= mod2;
        ans = (ans + mod2) % mod2;
    }

    ans = (ans + mod2) % mod2;
    cout << ans << endl;
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
