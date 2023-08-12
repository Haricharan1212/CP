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
    si s;

    int n;
    cin >> n;

    vi a(n);
    int curr = 0;
    s.insert(curr);

    rep(i, 0, n) cin >> a[i], curr += a[i], s.insert(curr);

    int chahel = curr;

    int ans = 0;
    for (auto i : s)
    {
        if ((chahel - i) % 2)
            continue;

        if (s.count(i + (chahel - i) / 2))
            ans++;
    }

    cout << ans - 1 << '\n';
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
