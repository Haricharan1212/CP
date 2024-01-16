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
    int n, m;
    cin >> n >> m;

    int r;
    cin >> r;

    vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(m + 1, vector<bool>(n + m + r + 1, true)));

    dp[0][0][0] = true;

    for (int i = 0; i < r; i++)
    {
        int t, d, coord;
        cin >> t >> d >> coord;

        if (d == 1)
        {
            for (int j = 0; j < m; j++)
                dp[coord][j][t] = false;
        }
        else if (d == 2)
        {
            for (int j = 0; j < n; j++)
                dp[j][coord][t] = false;
        }
    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 1; k <= n + m + r; k++)
            {
                if (dp[i][j][k] == false)
                    continue;
                dp[i][j][k] = dp[i][j][k - 1];
                if (i && dp[i - 1][j][k - 1])
                {
                    dp[i][j][k] = true;
                }
                if (j && dp[i][j - 1][k - 1])
                {
                    dp[i][j][k] = true;
                }
            }

    for (int k = 0; k <= n + m + r; k++)
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
                cout << dp[i][j][k] << " ";
            cout << endl;
        }
        cout << endl;
    }

    for (int i = 0; i <= n + m + r; i++)
        if (dp[n][m][i])
        {
            cout << i + 1 << endl;
            return;
        }

    cout << -1 << endl;
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
