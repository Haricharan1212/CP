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

    vi a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int l = a[0] + b[0];
    int r = a[n - 1] + b[n - 1];

    while (l < r)
    {
        int mid = l + (r - l) / 2;

        int cnt = 0;

        int j = n - 1;

        rep(i, 0, n)
        {
            while (j >= 0 && a[i] + b[j] > mid)
                j--;

            cnt += j + 1;
        }

        if (cnt >= k)
            r = mid;
        else
            l = mid + 1;
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