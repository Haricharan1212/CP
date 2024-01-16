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
    vi c(n);
    rep(i, 0, n) cin >> c[i];

    vi cols;
    vi colls;
    rep(i, 0, n)
    {
        if (c[i] == c[n - 1])
            cols.push_back(i);
        if (c[i] == c[0])
            colls.push_back(i);
    }

    if (c[0] == c[n - 1] && (int)colls.size() >= k)
        cout << "YES" << endl;
    else if ((int)cols.size() >= k && (int)colls.size() >= k && colls[k - 1] < cols[cols.size() - k])
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
