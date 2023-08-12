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

    vi diffs, a(n);

    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n - 1)
    {
        {
            diffs.push_back((a[i + 1] - a[i]));
        }
    }

    sort(diffs.begin(), diffs.end());

    if (diffs[0] < 0)
    {
        cout << 0 << endl;
    }
    else
        cout << diffs[0] / 2 + 1 << endl;
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
