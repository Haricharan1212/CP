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

#define float long double

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    float arr[n + 1][6 * n + 10];
    memset(arr, 0.0, sizeof(arr));

    rep(j, 1, 7) arr[1][j] = 1.0 / 6.0;

    rep(i, 2, n + 1)
    {
        rep(j, i, 6 * i + 1)
        {
            rep(k, 1, 7)
            {
                if (j - k >= 0)
                {
                    arr[i][j] += arr[i - 1][j - k] / 6.0;
                }
            }
        }
    }

    // rep(i, 1, n + 1)
    // {
    //     rep(j, 0, 6 * n + 1)
    //     {
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    float ans = 0;

    rep(i, a, b + 1)
    {
        ans += arr[n][i];
    }

    ans *= 1e6;
    ans = llround(ans);
    ans /= 1e6;

    cout << fixed << setprecision(6) << ans;
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
