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

// n choose k = (n-1) choose k + (n-1) choose k-1

// k = 1 is lite.

// b3k = 3ck a1 +             2ck a2 +                1ck a3
// b3k = 2ck a1 + 2c(k-1)a1 +   1ck a2 + 1ck-1 a2
// b3k = b2k + b2k-1

// a1
// 2 a1 + a2
// 3 a1 + 2a2 + a3

const int mod = 998244353;

// a b c d e f
// a + b, b - c, c + d, d - e, e + f
// a + c, b + d, c + e, d + f

// a b c d


int nchoosek(int n, int k)
{
    int ans = 1;

    rep(i, 1, n + 1) ans *= i;
    rep(i, 1, k + 1) ans /= i;
    rep(i, 1, n - k + 1) ans /= i;

    return ans;
}

void solve()
{
    int n, a1, x, y, m, kk;
    cin >> n >> a1 >> x >> y >> m >> kk;

    vi a(n + 1);
    a[1] = a1;
    rep(i, 2, n + 1) a[i] = (a[i - 1] * x + y) % m;

    // for (auto i: a) cout << i << ' ';
    // cout << endl;

    vii b(n + 1, vi(kk + 1, 0LL));

    int k = 1;

    int csum = 0;

    rep(i, 1, n + 1)
    {
        csum += a[i];
        b[i][1] = (b[i - 1][1] + csum) % mod;
    }

    rep(k, 2, kk + 1)
    {
        b[1][k] = 0;
        rep(i, 2, n + 1)
        {
            b[i][k] = b[i - 1][k] + b[i - 1][k - 1];
            b[i][k] %= mod;
        }
    }

    // int pp = 0;
    // rep(i, 1, n + 1)
    // {
    //     int ans = 0;

    //     rep(j, 1, i + 1)
    //     {
    //         ans += nchoosek(i - j + 1, kk) * a[j];
    //     }

    //     pp ^= (ans * i);

    //     cout << ans << ' ';
    // }
    // cout << pp << ' ';

    int ans = 0;
    rep(i, 1, n + 1) ans ^= (b[i][kk] * i);

    cout << ans << ' ';
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