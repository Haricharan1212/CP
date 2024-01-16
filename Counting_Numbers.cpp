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

int count(string s)
{
    reverse(s.begin(), s.end());

    int n = s.size();

    int dp[n][10][2][2];
    memset(dp, 0, sizeof(dp));
    // dp [number of digit, last digit, number of leading zeroes, tight?]

    rep(i, 0, n)
    {
        rep(j, 0, 10)
        {
            rep(k, 0, 2)
            {
                rep(l, 0, 2)
                {
                    int tight = l;
                    int leadingzeros = k;

                    int high = tight == 1 ? s[i] - '0' : 9;

                    for (int digit = 0LL; digit <= high; digit++)
                        if (digit == i && leadingzeros == 0)
                            continue;
                        else
                            dp[i][j][k][l] += (i == 0 ? 1 : dp[i - 1][digit][k && (digit == 0LL)][tight && (digit == high)]);

                    // cout << dp[i][j][k][l] << ' ';
                }
            }
        }
    }

    int ans = 0;
    rep (i, 0, 9)
        ans += dp[n - 1][i][1][1];

    return ans;
}

void solve()
{
    string a, b;
    cin >> a >> b;

    cout << count(a) << ' ';
    cout << count(b) << ' ';

    cout << count(b) - count(a) << endl;
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