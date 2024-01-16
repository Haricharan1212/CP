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

const int mod = 998244353;

int modexp (int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }

    return res;
}

int modinv(int a)
{
    return modexp(a, mod - 2);
}

void solve()
{
    int n, k;
    cin >> n >> k;

    int mx = 5e5 + 10;
    vi factorials = {1};
    rep(i, 1, mx + 1)
    {
        factorials.push_back((factorials.back() * i) % mod);
    }

    vi inv_factorials(mx + 1);

    rep(i, 0, mx + 1)
    {
        inv_factorials[i] = modinv(factorials[i]);
    }

    auto ncr = [&](int n, int r) {
        if (r > n)
            return 0LL;
        return (((factorials[n] * inv_factorials[r]) % mod) * inv_factorials[n - r]) % mod;
    };

    int ans = 0;

    rep (i, 1, n + 1){
        ans += ncr(n / i - 1, k - 1);
        ans %= mod;
    }

    cout << ans << '\n';
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