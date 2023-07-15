// Haricharan
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define vb vector<bool>
#define pi pair<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)
vi primes;

vi sieve(int n)
{
    vi isPrime(n + 1, -1);
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i] == -1)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (isPrime[j] == -1)
                    isPrime[j] = i;
            }
        }
    }
    return isPrime;
}

vi primefactors(int n)
{
    vi factors;

    if (primes[n] == -1)
        return {};

    while (n != 1 && primes[n] != -1)
    {
        factors.push_back(primes[n]);
        n /= primes[n];
    }

    if (n > 1)
        factors.push_back(n);

    sort(factors.begin(), factors.end());

    return factors;
}

void solve()
{
    int n;
    cin >> n;
    primes = sieve(n + 10);

    vi a = primefactors(n);
    int num = *a.rbegin();

    int l = (n / num - 1) * num + 1;
    int r = n;

    int ans = n - 1;

    rep(i, l, r + 1)
    {
        vi b = primefactors(i);

        // cout << i << ' ';
        // for (auto x : b)
        //     cout << x << ' ';

        // cout << endl;

        if (b.size() == 0)
            continue;

        int num = *b.rbegin();
        ans = min(ans, (i / num - 1) * num + 1);
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();

    return 0;
}
