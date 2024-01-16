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

int mod = 1e9 + 7;

vii matmul(vii a, vii b, int mod)
{
    int n = a.size();
    vii res(n, vi(n, 0));
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            rep(k, 0, n)
            {
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }
    return res;
}

vii matexp(vii a, int b, int mod)
{
    int n = a.size();
    vii res(n, vi(n, 0));
    rep(i, 0, n)
        res[i][i] = 1;
    while (b)
    {
        if (b & 1)
            res = matmul(res, a, mod);
        a = matmul(a, a, mod);
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;

    if (n == 0 || n == 1)
    {
        cout << n << endl;
        return;
    }

    vii a(2);
    a[0] = {1, 1};
    a[1] = {1, 0};

    // vii initial(6, vi(1, 0));
    // initial[0] = {1};

    vii b = matexp(a, n - 1, mod);

    cout << b[0][0] << ' ';

    // for (auto i : b)
    // {
    //     for (auto j : i)
    //         cout << j << " ";
    //     cout << endl;
    // }
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
