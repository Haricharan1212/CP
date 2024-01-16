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

vector<int> sieve(int n)
{
    // Time Complexity:- O(log(log(n)))

    vector<int> is_prime(n + 1, -1);
    is_prime[0] = is_prime[1] = -1;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] == -1 && 1LL * i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                if (is_prime[j] == -1)
                    is_prime[j] = i;
        }
    }
    return is_prime;
}

void solve()
{
    vi primes = sieve(2e7);

    int n;
    cin >> n;

    vi a(n);
    map<int, int> m;

    int g = 0;
    rep(i, 0, n)
    {
        cin >> a[i];
        g = __gcd(g, a[i]);
    }

    rep(i, 0, n)
    {
        int x = a[i];
        x /= g;

        if (primes[x] == -1)
        {
            m[x]++;
            continue;
        }

        while (primes[x] != -1)
        {
            int b = primes[x];
            while (x % b == 0)
                x /= b;
            m[b]++;
        }
        m[x]++;
    }

    int ans = n;

    for (auto i : m)
    {
        // cout << i.first << ' ' << i.second << endl;
        if (i.first == 1)
            continue;
        if (i.second == n)
            continue;
        ans = min(ans, n - i.second);
    }

    if (ans == n)
        cout << -1 << endl;
    else
        cout << ans << endl;
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
