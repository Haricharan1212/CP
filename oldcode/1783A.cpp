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

    if (n == 2 && a[0] == a[1])
    {
        cout << "NO" << endl;
        return;
    }

    sort(a.begin(), a.end());

    cout << "YES" << endl;

    cout << a[n - 1] << ' ' << a[0] << ' ';

    rep(i, 1, n - 1) cout << a[i] << " ";
    cout << endl;
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
