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
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    int f = 0;
    rep(i, 0, n)
    {
        int mn = a[i];
        int ans = 0;
        vi b(n);
        rep(j, 0, n)
        {
            b[i] = mn + (j - i);
        }

        rep(j, 0, i)
        {
            if (a[j] <= b[j] && (j == 0 || a[j - 1] < a[j]))
                continue;
            else
                ans += b[j] - a[j], a[j] = b[j];
        }

        for (int j = n - 1; j >= 0; j--)
        {
            if (a[j] >= b[j] && (j == n - 1 || a[j] < a[j + 1]))
                continue;
            else
                ans += abs(b[j] - a[j]), a[j] = b[j];
        }

        cout << i << ' ' << ans << endl;

        f = min(ans, f);
    }

    cout << f << endl;
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
