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

    int n, k, q;
    cin >> n >> k >> q;

    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int current = 0;
    int ans = 0;
    rep(i, 0, n)
    {
        if (a[i] <= q)
        {
            current++;
        }
        else
            current = 0;

        if (current >= k)
        {
            ans += (current - k) + 1;
        }
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
