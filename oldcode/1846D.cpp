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
    float d, h;
    cin >> n >> d >> h;

    vector<float> a(n);
    rep(i, 0, n) cin >> a[i];

    reverse(a.begin(), a.end());

    int curr = a[0];
    float ans = 0;
    ans += 1 / 2.0 * d * h;

    rep(i, 1, n)
    {
        if (a[i] + h <= curr)
        {
            ans += 1 / 2.0 * d * h;
        }
        else
        {
            float l1 = (h - (curr - a[i])) / h * d;
            ans += 1 / 2.0 * (d + l1) * (curr - a[i]);
        }

        // cout << ans << ' ';

        curr = a[i];
    }

    cout << fixed << setprecision(30) << ans << endl;
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
