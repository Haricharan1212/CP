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

int mod2 = 998244353;

int modexp(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod2;
        a = (a * a) % mod2;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n, a1, x, y, m, k;
    cin >> n >> a1 >> x >> y >> m >> k;

    int nck = 1;
    vi b(n + 1, 0);

    int ai = a1;
    int prefy = 0;

    int bi = 0;
    int ans = 0;

    rep(i, 1, n + 1)
    {
        if (i < k)
            continue;

        if (i == k)
        {
            bi = ai;
        }
        else
        {
            bi = (bi * x + prefy * (y)) + nck * a1;
        }
        bi %= mod2;

        prefy += nck;
        prefy %= mod2;

        nck = nck * (i + 1) * modexp(i + 1 - k, mod2 - 2);
        nck %= mod2;

        cout << bi << ' ';

        ans ^= bi * i;
    }

    // for (auto i : b)
    // {
    //     cout << i << " ";
    // }

    // rep(i, 1, n + 1)
    // {
    //     ans ^= (b[i] * (i));
    // }

    cout << ans << endl;
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
