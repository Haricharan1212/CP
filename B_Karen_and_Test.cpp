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

// a b c d e f
// a + b, b - c, c + d, d - e, e + f
// a + c, b + d, c + e, d + f
// something,
// a + 2c + e, b + 2d + f

// a b c d e f g h
//
// a + c, b + d, c + e, d + f, e + g, f + h
//
// a + 2c + e, b + 2d + f, c + 2e + g, d + 2f + h

// a + 3c + 3e + g, b + 3d + 3f + h

// a b c d e
// a + b, b - c, c + d, d - e

const int mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;

    vi a(n);
    rep(i, 0, n) cin >> a[i];

    if (n == 1)
    {
        cout << a[0];
        return;
    }
    else if (n == 2)
    {
        cout << a[0] + a[1];
        return;
    }
    else if (n == 3)
    {
        // a b c
        // a + b, b - c
        // a + 2b - c

        cout << a[0] + 2 * a[1] - a[2];
        return;
    }

    if (n % 2 == 1)
    {
        vi b(n - 1);
        rep(i, 0, n - 1) b[i] = a[i] + a[i + 1] * (i % 2 == 0 ? +1 : -1);
        n--;
        a = b;
    }

    int f = a[0] + a[n - 2], g = a[1] + a[n - 1];

    for (int i = 2; i < n - 2; i += 2)
    {
        f += (n - 1) * a[i];
    }

    for (int i = 3; i < n - 1; i += 2)
    {
        g += (n - 1) * a[i];
    }

    f + g;

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