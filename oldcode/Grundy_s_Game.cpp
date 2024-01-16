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

const int cnt = 5005;

vi dp;

void solve()
{
    int n;
    cin >> n;

    if (n > cnt)
    {
        cout << "first" << endl;
        return;
    }

    cout << (dp[n] ? "first" : "second") << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;

    // P position = 0, N position = 1

    dp = vi(cnt, 0);

    rep(i, 3, cnt)
    {
        si current;
        rep(j, 1, (i + 1) / 2)
        {
            current.insert(dp[j] ^ dp[i - j]);
            // if (dp[j] == 0 && dp[i - j] == 0)
            // {
            //     dp[i] = 1;
            //     break;
            // }
        }

        rep(j, 0, cnt)
        {
            if (current.find(j) == current.end())
            {
                dp[i] = j;
                break;
            }
        }
    }

    // for (int i = 0; i < cnt; i++)
    //     cout << dp[i] << ' ';

    while (tc--)
        solve();

    return 0;
}
