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

vector<int> primes;

vector<int> sieve(int n)
{
    // Time Complexity:- O(log(log(n)))

    vector<int> is_prime(n + 1, -1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] == -1 && 1LL * i * i <= n)
        {
            is_prime[i] = i;
            for (int j = i * i; j <= n; j += i)
                if (is_prime[j] == -1)
                    is_prime[j] = i;
        }
        else if (is_prime[i] == -1)
            is_prime[i] = i;
    }
    return is_prime;
}

int operate(int x)
{
    int ans = 1;

    while (x > 1)
    {
        int fact = primes[x];

        if (fact == -1)
            return x;
        if (x % (fact * fact) == 0)
        {
            x = x / (fact * fact);
        }
        else
        {
            ans *= primes[x];
            x = x / primes[x];
        }
    }
    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    set<int> s;
    int count = 0;

    rep(i, 0, n)
    {
        a[i] = operate(a[i]);
        if (s.find(a[i]) == s.end())
        {
            s.insert(a[i]);
        }
        else
        {
            s.clear();
            s.insert(a[i]);
            count++;
        }
    }

    if (s.size())
        count++;

    cout << count << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;

    primes = sieve(1e7 + 5);

    while (tc--)
    {
        solve();
    }

    return 0;
}
