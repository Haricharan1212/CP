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

int modexp(int a, int b, int m)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    res += m;
    res %= m;
    return res;
}

int factorial(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
    {
        res *= i;
        res %= 1000000007;
    }
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int ans = factorial(n + m - 1);
    ans *= modexp(factorial(n - 1), 1000000007 - 2, 1000000007);
    ans %= 1000000007;
    ans *= modexp(factorial(m), 1000000007 - 2, 1000000007);
    ans %= 1000000007;

    cout << ans << '\n';
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
