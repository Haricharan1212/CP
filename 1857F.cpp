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
    map<int, int> m;

    rep(i, 0, n) cin >> a[i], m[a[i]]++;

    int q;
    cin >> q;

    rep(i, 0, q)
    {
        //        ai^2 - ai x + y = 0
        //        ai = (x +- sqrt(x^2 - 4y))/2

        int x, y;
        cin >> x >> y;

        int sq = sqrtl(x * x - 4 * y);

        if (x * x < 4 * y || sq * sq != x * x - 4 * y)
        {
            cout << 0 << " ";
            continue;
        }

        int f = (x + sq) / 2;

        if (m.count(f) && m.count(x - f))
        {
            if (f != x - f)
                cout << m[f] * m[x - f] << " ";
            else
                cout << m[f] * (m[f] - 1) / 2 << " ";
        }
        else
            cout << 0 << " ";
    }

    cout << endl;
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
