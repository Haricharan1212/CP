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
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());

    int ans = 1;
    int curr = 1;

    rep(i, 0, n - 1)
    {
        if (a[i + 1] - a[i] > k)
            ans = max(ans, curr), curr = 1;
        else
            curr++;
    }
    ans = max(ans, curr);

    cout << n - ans << endl;
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
