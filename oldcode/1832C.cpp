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
    si s;
    rep(i, 0, n) cin >> a[i], s.insert(a[i]);

    if (s.size() == 1)
    {
        cout << 1 << endl;
        return;
    }

    vi b = {a[0]};
    rep(i, 1, n)
    {
        if (a[i] == a[i - 1])
            continue;
        b.push_back(a[i]);
    }

    a = b;
    n = a.size();

    vi ans;
    ans.push_back(a[0]);

    rep(i, 1, n - 1)
    {
        if (a[i] < a[i - 1] && a[i] < a[i + 1])
            ans.push_back(a[i]);
        else if (a[i] > a[i - 1] && a[i] > a[i + 1])
            ans.push_back(a[i]);
    }
    ans.push_back(a[n - 1]);

    cout << ans.size() << endl;
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
