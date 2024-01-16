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
    int n, k, x;
    cin >> n >> k >> x;

    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    vi pref = a;

    rep(i, 1, n)
    {
        pref[i] += pref[i - 1];
    }

    int anss = -1e18;

    // 1 2 2
    // remove nothing:
    // -1 - 3 -> -4
    // remove 3
    // 

    if (k == n){
        anss = 0LL;
    }

    for (int i = max(0LL, n - k - 1); i < n; i++)
    {
        int ans;
        if (i - x >= 0)
            ans = (pref[i] - pref[i - x]) * -1 + pref[i - x];
        else
            ans = -1 * pref[i];
        
        anss = max(ans, anss);
    }

    cout << anss << "\n";
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