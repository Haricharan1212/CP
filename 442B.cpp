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
    int n;
    cin >> n;

    vector<long double> a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int dp[n + 1][2];

    dp[0][0] = 0;
    dp[0][1] = 0;

    rep(i, 1, n + 1)
    {
        dp[i][1] = dp[i - 1][0] * a[i - 1];
        dp[i][0] = dp[i - 1][1] * (1 - a[i - 1]);
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
