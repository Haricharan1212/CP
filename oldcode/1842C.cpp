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
    map<int, int> m;

    int n;
    cin >> n;

    vi a(n);
    vi dp(n + 1, 1e9);
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        a[i] = x;
        dp[i] = i + 1;

        if (m.find(x) == m.end())
            m[x] = i, dp[i] = (i == 0 ? 0 : dp[i - 1]) + 1;
        else
            dp[i] = min((i == 0 ? 0 : dp[i - 1]) + 1, m[x] == 0 ? 0 : dp[m[x] - 1]);
    }

    cout << n - dp[n - 1] << endl;
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
