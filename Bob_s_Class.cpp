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
    int n, k;
    cin >> n >> k;

    int dp[n + 1][n + 1];

    int mod = 1e9 + 7;

    rep(i, 1, n + 1)
    {
        if (i == 1)
        {
            dp[i][1] = 1;
            continue;
        }
        rep(j, 1, i + 1)
        {
            if (j == 1)
                dp[i][j] = dp[i - 1][j] * (i - 1);
            else if (j == i)
                dp[j][i] = 1;
            else
                dp[i][j] = dp[i - 1][j] * (i - 1) + dp[i - 1][j - 1];

            dp[i][j] %= mod;
        }
    }

    // rep(i, 0, n + 1)
    // {
    //     rep(j, 0, n + 1)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[n][k] << endl;
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
