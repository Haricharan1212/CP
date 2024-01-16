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
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    si divs1, divs2, divs;

    rep(i, 1, sqrt(m1) + 1)
    {
        if (m1 % i == 0)
        {
            divs1.insert(i);
            divs1.insert((m1) / i);
        }
    }

    rep(i, 1, sqrt(m2) + 1)
    {
        if (m2 % i == 0)
        {
            divs2.insert(i);
            divs2.insert((m2) / i);
        }
    }

    for (auto i : divs1)
    {
        for (auto j : divs2)
        {
            divs.insert(i * j);
        }
    }

    int x = 0, cnt = 0;
    for (auto i : divs)
    {
        int num = (i + n - 1) / n;
        while (num <= n)
        {
            if (i % num == 0 && i / num <= n)
            {
                x ^= num;
                cnt++;
                // cout << i << ' ' << num << endl;
                break;
            }

            num++;
        }
    }

    cout << cnt << ' ' << x << endl;
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
