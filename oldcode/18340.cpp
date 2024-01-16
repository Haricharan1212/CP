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

    int one = 0;
    int m = 0;
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        if (x == 1)
            one++;
        else
            m++;
    }

    int ans = n;

    for (int i = 0; i < n; i += 2)
    {
        if (i <= n - i)
            ans = min(ans, abs(m - i));
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