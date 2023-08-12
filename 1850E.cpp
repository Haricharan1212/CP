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

#define float long double

void solve()
{
    int n, c;
    cin >> n >> c;

    vi a(n);
    float sum = 0, arsq = 0;
    rep(i, 0, n) cin >> a[i], sum += a[i], arsq += a[i] * a[i];

    int w = (-4 * sum + sqrtl(16 * sum * sum + 16 * n * (c - arsq))) / (8 * n);

    cout << w << endl;
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
