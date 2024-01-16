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

    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int mx = 1 << n;

    vector<pi> dp(mx, pi(1e9, 1e9));

    dp[0] = {1, 0};

    for (int i = 1; i < mx; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                int num = i ^ (1 << j);

                pi poss = dp[num];

                if (poss.second + a[j] <= x)
                {
                    poss.second += a[j];
                }
                else
                {
                    poss.second = a[j];
                    poss.first++;
                }

                dp[i] = min(dp[i], poss);
            }
        }
    }

    // for (auto i : dp)
    //     cout << i.first << ' ' << i.second << endl;

    cout << dp[mx - 1].first << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();

    return 0;
}
