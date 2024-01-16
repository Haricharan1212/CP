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

    map<pi, int> m;

    int n;
    cin >> n;

    vector<pi> a(n);

    rep(i, 0, n)
    {
        cin >> a[i].first >> a[i].second;
    }

    rep(i, 0, n)
    {
        rep(j, i + 1, n)
        {
            int ysl = a[i].second - a[j].second;
            int xsl = a[i].first - a[j].first;
            int g = __gcd(ysl, xsl);
            ysl /= g;
            xsl /= g;

            if (xsl < 0)
            {
                ysl *= -1;
                xsl *= -1;
            }

            m[{ysl, xsl}]++;
        }
    }

    int s = 0;

    for (auto i : m)
    {
        cout << i.first.first << ' ' << i.first.second << ' ' << i.second << endl;
        s += ((i.second - 1) * i.second) / 2;
    }

    int ans = 0;
    for (auto i : m)
    {
        int x = (i.second * (i.second - 1)) / 2;
        ans += (s - (x)) * x;
    }

    cout << ans / 2 << endl;
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
