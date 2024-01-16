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
    rep(i, 0, n) cin >> a[i];

    vi ans(n, -1);
    stack<pi> s;
    s.push({0, 0});

    rep(i, 0, n)
    {
        while (s.top().first >= a[i])
            s.pop();
        ans[i] = s.top().second;
        s.push({a[i], i + 1});
    }

    for (auto i : ans)
        cout << i << ' ';
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
