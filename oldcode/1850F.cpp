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
    map<int, int> m;
    rep(i, 0, n) cin >> a[i], m[a[i]]++;

    vi dp(n + 2, 0);

    for (auto i : m)
    {
        rep(j, 1, n + 1)
        {
            if (j * i.first > n)
                break;
            dp[j * i.first] += i.second;
        }
    }

    int ans = 0;
    for (auto i : dp)
        ans = max(ans, i);

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