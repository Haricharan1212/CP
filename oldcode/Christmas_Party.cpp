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

int factorial(int n)
{
    int res = 1;
    rep(i, 1, n + 1)
    {
        res = (res * i) % mod;
    }
    return res;
}

int modexp(int a, int b, int mod)
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

void solve()
{
    int n;
    cin >> n;

    int ans = 0;
    int f = factorial(n);

    int curr = 1;

    rep(i, 2, n + 1)
    {
        curr *= i;
        curr %= mod;
        ans += f * (modexp(curr, mod - 2, mod) % mod) % mod * (i % 2 == 0 ? 1 : -1);
        ans %= mod;
        ans += mod;
        ans %= mod;
    }

    cout << ans % mod << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //    cin >> tc;
    while (tc--)
        solve();

    return 0;
}
