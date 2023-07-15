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

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> dp(2 * n + 5, 1e18);

    dp[0] = 0;

    rep(i, 1, n + 1)
    {
        if (i % 2)
            dp[i] = min(dp[i - 1] + x, dp[(i + 1) / 2] + x + y);
        else
            dp[i] = min(dp[i - 1] + x, dp[(i) / 2] + y);
    }

    // for (auto i : dp)
    //     cout << i << ' ';
    cout << dp[n] << endl;
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
