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

bool check(int n, int k, vi &a, int mid)
{
    // mid many councils
    int reqd = k * mid;

    int have = 0;
    rep(i, 0, n)
    {
        have += min(a[i], mid);
    }

    return have >= reqd;
}

void solve()
{
    int n, k;
    cin >> k >> n;

    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int l = 0;
    int r = 1e15;

    while (l < r)
    {
        int mid = (l + r + 1) / 2;

        if (check(n, k, a, mid))
            l = mid;
        else
            r = mid - 1;
    }

    cout << l << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();

    return 0;
}