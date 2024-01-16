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
    int n, x;
    cin >> n >> x;

    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    int dp[x + 1];
    for (int i = 1; i <= x; i++)
        dp[i] = -1;
    dp[0] = 0;

    // 0 -1 -1 -1 -1 -1

    for (int i = 0; i < n; i++)
    {
        int current_coin = c[i];
        for (int j = 1; j <= x; j++)
        {
            if (j - current_coin < 0)
                continue;
            if (dp[j - current_coin] == -1)
                continue;

            if (dp[j] == -1)
                dp[j] = dp[j - current_coin] + 1;
            else
                dp[j] = min(dp[j - current_coin] + 1, dp[j]);
        }
    }

    // for (int i = 0; i <= x; i++)
    //     cout << dp[i] << ' ';

    cout << dp[x];
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
