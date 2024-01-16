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

int mod;

int modexp(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % mod;
    int res = modexp(a, b / 2);
    res = (res * res) % mod;
    if (b % 2 == 1)
        res = (res * a) % mod;
    return res;
}

void solve()
{
    int n;
    cin >> n;
    mod = n;

    vi b(n);
    rep(i, 0, n)
    {
        cin >> b[i];
    }

    vii a(n, vi(n, 0LL));

    if (0)
    {
        a = {{0, 1}, {0, 0}};
    }
    else
    {
        rep(shift, 0, n)
        {
            rep(i, 0, n)
            {
                int j = (i + shift) % n;
                if ((i % 2 == 1) && (j % 2 == 1))
                    a[i][j] = 1;
                else
                    a[i][j] = 0;
            }
        }
    }

    // for  (auto i: a)
    // {
    //     for (auto j: i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    rep(i, 0, n)
    {
        int diff = b[i] - a[i][i];

        rep(j, 0, n)
        {
            a[i][j] += diff;
            a[i][j] = (a[i][j] + mod) % mod;
        }
    }

    for (auto i : a)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
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