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

int factorial(int n)
{
    int res = 1;
    rep(i, 1, n + 1)
    {
        res = (res * i) % mod;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;

    if (n % 2 == 1)
    {
        cout << 0 << endl;
        return;
    }

    n /= 2;

    cout << (factorial(2 * n) * modexp(factorial(n), mod - 2, mod) % mod * modexp(factorial(n + 1), mod - 2, mod) % mod) % mod << endl;
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
