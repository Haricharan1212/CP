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
const int mod = 1e9 + 7;

int summ(int l, int r)
{
    if (l > r)
        return 0;

    r %= mod;
    l %= mod;

    return (r * (r + 1)) / 2 - ((l * (l - 1)) / 2) % mod;
}

void solve()
{
    int n;
    cin >> n;
    int ans = 0;

    rep(i, 1, ceil(sqrtl(n)) + 1)
    {
        int f = (n / i - i + 1) * i;
        f %= mod;
        ans += max(0LL, f);
        ans += summ(i + 1, n / i), ans %= mod;
    }

    ans += mod;
    ans %= mod;

    cout << ans;
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
