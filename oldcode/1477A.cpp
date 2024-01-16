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
    int n, k;
    cin >> n >> k;
    vi a(n);
    int ge = 0;
    int go = 0;
    rep(i, 0, n) cin >> a[i], g = __gcd(g, abs(a[i]));
    if (g == 0 && k == 0)
    {
        cout << "YES" << endl;
        return;
    }
    else if (g == 0 && k != 0)
    {
        cout << "NO" << endl;
        return;
    }
    else if (k % g == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
