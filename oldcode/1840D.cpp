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
    int n;
    cin >> n;

    vi a(n);
    set<int> s;

    rep(i, 0, n)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    a = {};

    for (auto i : s)
        a.push_back(i);

    n = a.size();

    if (n <= 3)
    {
        cout << 0 << endl;
        return;
    }

    vector<pi> diffs;

    rep(i, 0, n - 1)
    {
        diffs.push_back({a[i + 1] - a[i], i});
    }

    sort(diffs.begin(), diffs.end(), greater<pi>());

    int ans = 1e18;

    rep(i2, 0, n)
    {
        int i1 = 0;
        int i4 = n - 1;
        int i3 = lower_bound(a.begin(), a.end(), a[i2 + 1] + (a[n - 1] - a[i2 + 1]) / 2) - a.begin();
        ans = min(ans, max((a[i2] - a[i1] + 1) / 2, max((a[i3] - a[i2 + 1] + 1) / 2, (a[i4] - a[i3 + 1] + 1) / 2)));
        i3--;
        if (i3 < 0)
            continue;
        ans = min(ans, max((a[i2] - a[i1] + 1) / 2, max((a[i3] - a[i2 + 1] + 1) / 2, (a[i4] - a[i3 + 1] + 1) / 2)));
    }

    cout << ans << endl;
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
