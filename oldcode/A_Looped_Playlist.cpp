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
    int n, p;
    cin >> n >> p;

    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int onesum = accumulate(a.begin(), a.end(), 0);

    int ans = (p / onesum) * n;
    p %= onesum;

    rep(i, 0, n) a.push_back(a[i]);

    int l = 0;
    int csum = 0;
    int anss = 1e9;

    int ansstart = 0;

    rep(r, 0, 2 * n)
    {
        csum += a[r];

        while (csum - a[l] >= p && l <= r)
        {
            csum -= a[l];
            l++;
        }

        // cout << l << ' ' << r << ' ' << csum << endl;

        if (r - l + 1 < anss && csum >= p)
        {
            anss = r - l + 1;
            ansstart = l;
        }
    }

    // cout << ans << ' ';

    cout << ansstart % n + 1 << ' ' << ans + anss << endl;
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