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
    int od = 0, ev = 0;
    rep(i, 0, n) cin >> a[i], (a[i] % 2 == 0) ? ev++ : od++;

    if (n % 2 == 0)
    {
        if (ev != od)
        {
            cout << -1 << endl;
            return;
        }
        int f = 0, g = 0;
        rep(i, 0, n) if (a[i] % 2 == 0 && i % 2 == 0) f++;
        rep(i, 0, n) if (a[i] % 2 == 0 && i % 2 == 1) g++;

        cout << min(f, g) << endl;
    }
    else
    {
        if (ev == od + 1)
        {
            int f = 0, g = 0;
            rep(i, 0, n) if (a[i] % 2 == 0 && i % 2 == 1) f++;

            cout << f << endl;
        }
        else if (ev == od - 1)
        {
            int f = 0, g = 0;
            rep(i, 0, n) if (a[i] % 2 == 0 && i % 2 == 0) f++;

            cout << f << endl;
        }
        else
        {
            cout << -1 << endl;
            return;
        }
    }
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
