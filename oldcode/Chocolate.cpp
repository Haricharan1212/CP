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

    int m, n;
    cin >> m >> n;

    vi x(m - 1), y(n - 1);
    rep(i, 0, m - 1) cin >> x[i];
    rep(i, 0, n - 1) cin >> y[i];

    int dp[n][m];

    rep(i, 1, n) dp[i][0] = dp[i - 1][0] + y[i - 1];
    rep(i, 1, m) dp[0][i] = dp[0][i - 1] + x[i - 1];

    rep(i, 1, n) rep(j, 1, m)
    {
        int a = dp[i - 1][j] + (i)*y[i - 1];
        int b = dp[i][j - 1] + (j)*x[j - 1];

        dp[i][j] = min(a, b);
    }

    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    cout << dp[n - 1][m - 1] << "\n";
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
