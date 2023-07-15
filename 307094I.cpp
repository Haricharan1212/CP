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
    int n, ss;
    cin >> n >> ss;

    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    set<pi> s;
    s.insert({0, 0});
    int prefs = 0;
    int minlen = 1e9;
    rep(i, 0, n)
    {
        prefs += a[i];
        int reqsum = ss - prefs;

        auto p = *s.lower_bound({reqsum, -1LL});

        if (p.first == reqsum)
        {
            minlen = min(minlen, i + 1 - p.second + 1);
        }
        else
            continue;

        p = *s.lower_bound({prefs, -1LL});

        if (p.first == prefs)
        {
            s.erase(p);
        }
        s.insert({prefs, i + 1});
    }

    if (minlen == 1e9)
        cout << -1 << endl;
    else
        cout << minlen << endl;
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
