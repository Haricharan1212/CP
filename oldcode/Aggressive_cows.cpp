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

#include <ext/pb_ds/assoc_container.hpp>

void solve()
{
    int n, c;
    cin >> n >> c;

    vi a(n);

    rep(i, 0, n)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vi diff;
    rep(i, 0, n - 1) diff.push_back(a[i + 1] - a[i]);

    sort(diff.begin(), diff.end(), greater<int>());

    cout << diff[c] << endl;
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
