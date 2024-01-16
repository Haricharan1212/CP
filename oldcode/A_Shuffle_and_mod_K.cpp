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
    int n, mod;
    cin >> n >> mod;

    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    rep (i, 0, n) {
        a[i] %= mod;
    }

    sort(a.begin(), a.end(), greater<int>());

    int ans = 0;

    rep (i, 0, n - 1) ans += (a[i + 1] - a[i] + mod);

    cout << ans << endl;

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