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
    int n;
    cin >> n;

    vector<float> r(n);
    rep(i, 0, n) cin >> r[i];

    vector<float> ans(n, 0);

    rep(i, 1, n)
    {
        rep(j, 1, r[i] + 1)
        {
            rep(prev, 0, i)
            {
                // cout << i << j << prev << ' ';
                ans[i] += (1.0 / r[i]) * max((long double)0, ((r[prev] - j) / r[prev]));

                // cout << (1.0 / r[i]) * max((long double)0, ((r[prev] - j) / r[prev])) << 'u';

            }
        }
    }

    // for (auto i: ans) cout << fixed << setprecision(10) << i << endl;

    float anss = 0;
    rep(i, 0, n) anss += ans[i];
    // anss += 1e-9;

    // anss *= 1e6;
    // anss = round(anss);
    // anss /= 1e6;

    cout << setprecision(6) << fixed;
    cout << anss << endl;
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