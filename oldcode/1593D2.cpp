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

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define vi vector<int>
#define rep(var, l, r) for (int var = l; var < r; var++)
#define repr(var, r, l) for (int var = r; var > l; var--)

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

vector<bool> primes;

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    map<int, int> m;
    rep(i, 0, n) m[a[i]]++;

    for (auto i : m)
        if (i.second >= n / 2)
        {
            cout << "-1\n";
            return;
        }

    int ans = 2;
    rep(k, 1, 2e6)
    {
        if (!(primes[k]))
            continue;

        map<int, int> m;

        rep(i, 0, n)
        {
            m[a[i] % k]++;
        }
        for (auto i : m)
        {
            if (i.second >= n / 2)
            {
                ans = max(ans, k);
            }
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;

    primes = sieve(2e6 + 5);

    while (tc--)
    {
        solve();
    }

    return 0;
}
