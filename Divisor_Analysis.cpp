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

int modexp(int a, int b, int m)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    res += m;
    res %= m;
    return res;
}

void solve()
{
    int n;
    cin >> n;
    int nd = 1, sd = 1;
    int nn = 1;
    int sq = 1;
    bool f = true;

    rep(i, 0, n)
    {
        int a, b;
        cin >> a >> b;

        nd *= b + 1;
        nd %= 1000000007;

        // 1 + a + a^2 + .... a^b = (a^(b+1) - 1) / (a - 1)

        int c = (modexp(a, b + 1, 1000000007) - 1) * modexp(a - 1, 1000000007 - 2, 1000000007);
        c %= 1000000007;
        // cout << c << ' ';

        sd *= c;
        sd %= 1000000007;
        nn *= modexp(a, b, 1000000007);
        nn %= 1000000007;
        sq *= modexp(a, b / 2, 1000000007);
        sq %= 1000000007;

        if (b % 2 == 1)
            f = false;
    }

    int pd = modexp(nn, (nd) / 2, 1000000007);
    if (f)
    {
        pd *= sq;
        pd %= 1000000007;
    }

    cout << nd << ' ' << sd << ' ' << pd << endl;
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
