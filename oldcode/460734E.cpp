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
    int ans = 1e9;
    rep(i, 0, n)
    {
        cin >> a[i];

        if (a[i] == 1)
        {
            ans = min(ans, 1LL);
            continue;
        }
        else if (a[i] == 0)
        {
            ans = 0;
            continue;
        }
        int t;
        if (a[i] % 2 == 0)
        {
            if (a[i] % 4 == 2)
                t = a[i] + 1;
            else
                t = a[i] - 1;
        }
        else
        {
            if (a[i] % 4 == 1)
                t = a[i];
            else
                t = a[i] + 2;
        }
        ans = min(ans, t);
    }

    cout << ans << endl;
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
