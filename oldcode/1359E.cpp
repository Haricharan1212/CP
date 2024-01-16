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

int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = (fact * i) % mod;
    }
    return fact;
}

int modexp(int a, int b)
{
    int res = 1;
    a %= mod;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int nck(int n, int k)
{
    int ans = factorial(n) * modexp(factorial(n - k) * factorial(k), mod - 2);
    ans %= mod;
    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    int ans = nck(n - 1, k - 1);
    cout << ans << endl;

    if (k > 25)
    {
    }
    else
    {
    }
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
