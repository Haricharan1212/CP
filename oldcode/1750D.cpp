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

int mod2 = 998244353;

void solve()
{
    int n, m;
    cin >> n >> m;

    int ans = 1;

    vi a(n);
    rep(i, 0, n) cin >> a[i];

    rep(i, 1, n)
    {
        if (a[i - 1] % a[i] != 0)
        {
            ans *= 0;
            break;
        }
        if (a[i] == a[i - 1])
            ans *= m / a[i];
        else
            ans *= m / a[i] - m / (a[i - 1] / a[i]);
        ans %= mod2;
        ans += mod2;
        ans %= mod2;
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
        solve();

    return 0;
}
