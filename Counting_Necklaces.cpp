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

int mod = 1e9 + 7;
int mx = 1e6 + 5;

vi factorials;
void precompute()
{
    factorials = vi(mx, 1);
    rep(i, 1, mx)
    {
        factorials[i] = factorials[i - 1] * i % mod;
    }
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

int ncr(int n, int k)
{
    if (k > n)
        return 0;
    return factorials[n] * modexp(factorials[n - k], mod - 2, mod) % mod * modexp(factorials[k], mod - 2, mod) % mod;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int ans = modexp(m, n, mod);

    rep(i, 2, n + 1)
    {
        if (n % i)
            continue;
        int mci = ncr(m, i);

        ans = (ans - mci * modexp(m, n / i, mod) % mod + mod) % mod;
        cout << ans << ' ';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //    cin >> tc;
    precompute();
    while (tc--)
        solve();

    return 0;
}
