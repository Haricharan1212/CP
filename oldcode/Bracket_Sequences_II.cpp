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

int factorial(int n, int mod)
{
    if (n == 0)
        return 1;

    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans *= i;
        ans %= mod;
    }
    return ans;
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

int ncr(int n, int r) // nCr
{
    if (r > n || r < 0)
        return 0;

    return (((factorial(n, mod) * modexp(factorial(r, mod), mod - 2, mod)) % mod) * modexp(factorial(n - r, mod), mod - 2, mod)) % mod;
}

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (n % 2 == 1)
    {
        cout << 0 << endl;
        return;
    }

    int open = 0, close = 0;

    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '(')
            open++;
        else if (s[i] == ')')
            close++;

        if (open < close)
        {
            cout << 0 << endl;
            return;
        }
    }

    // if (open > n / 2 || close > n / 2 || open < close)
    // {
    //     cout << 0 << endl;
    //     return;
    // }

    int a = open, b = close;

    n /= 2;

    int l = n - (b - 1);
    int r = n - (a + 1);

    int ll = n - a;
    int rr = n - b;

    // cout << l << " " << r << " " << ll << " " << rr << endl;

    int ans = (ncr(ll + rr, rr) - ncr(l + r, r)) % mod;
    ans = (ans + mod) % mod;
    cout << ans << endl;
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
