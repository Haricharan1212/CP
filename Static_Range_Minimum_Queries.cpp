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

const int mx = 20;

void solve()
{
    int n, q;
    cin >> n >> q;

    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vii st(n, vi(mx, 0));

    rep(i, 0, n) st[i][0] = a[i];

    rep(j, 1, mx)
    {
        rep(i, 0, n)
        {
            if (i + (1 << j) <= n)
            {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
            else
                st[i][j] = -1;
        }
    }

    // rep(i, 0, n)
    // {
    //     rep(j, 0, mx)
    //     {
    //         cout << st[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    while (q--)
    {
        int ans = 1e9 + 1;

        int l, r;
        cin >> l >> r;
        l--, r--;

        for (int j = mx - 1; j >= 0; j--)
        {
            if (l + (1 << j) <= r + 1)
            {
                ans = min(ans, st[l][j]);
                l += (1 << j);
            }
        }

        cout << ans << "\n";
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
