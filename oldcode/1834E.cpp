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

int lcm(int a, int b)
{
    return a * b / __gcd(a, b);
}

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int mx = 5 * n + 100;
    vector<bool> ans(mx, false);

    rep(i, 0, n)
    {
        int cur = 1;
        rep(j, i, min(i + 20, n))
        {
            cur = lcm(cur, a[j]);
            if (cur >= mx)
                break;
            if (cur < mx)
            {
                ans[cur] = true;
            }
        }
    }

    rep(i, 1, 5 * n + 10)
    {
        if (ans[i] == true)
            continue;

        int prod = 1;
        rep(j, 0, n)
        {
            if (i % a[j])
                prod = 1;
            else
            {
                prod = lcm(prod, a[j]);

                if (prod == i)
                {
                    ans[i] = true;
                    break;
                }
            }
        }

        if (ans[i] == false)
        {
            cout << i << endl;
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
