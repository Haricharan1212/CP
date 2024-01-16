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
    vi primes = sieve(1e7 + 5);

    int n;
    cin >> n;

    vi a(n);
    vector<pi> anss(n);

    // rep(i, 0, 20) cout << i << ' ' << primes[i] << endl;

    rep(i, 0, n)
    {
        int x;
        cin >> x;
        a[i] = x;
        pi ans;
        if (primes[x] == -1)
        {
            ans = {-1, -1};
        }
        else
        {
            int b = primes[x];

            while (x % b == 0)
            {
                x /= b;
            }
            if (__gcd(x + b, a[i]) == 1 && x > 1 && b > 1)
                ans = {b, x};
            else
                ans = {-1, -1};
        }
        anss[i] = ans;
    }

    rep(i, 0, n) cout << anss[i].first << " ";
    cout << endl;
    rep(i, 0, n) cout << anss[i].second << " ";
    cout << endl;
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