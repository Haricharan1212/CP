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

    string s, t;
    cin >> s >> t;

    int cnt = 0, cntt = 0;

    rep(i, 0, n)
    {
        if (s[i] != t[i])
            cnt++;
        if (s[i] != t[n - 1 - i])
            cntt++;
    }

    int ans = 1e9;

    if (cnt % 2 == 1)
        ans = min(ans, 2 * cnt - 1);
    else
        ans = min(ans, 2 * cnt);

    if (cntt == 0)
        ans = min(ans, 2LL);
    else if (cntt % 2 == 1)
        ans = min(ans, 2 * cntt);
    else
        ans = min(ans, 2 * cntt - 1);

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
