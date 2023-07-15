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

bool check(vector<pi> &a, vector<int> &b, int mid, int n)
{
    int m = a.size();
    int q = b.size();

    vi c(n, 0);

    rep(i, 0, mid) c[b[i] - 1] = 1;

    rep(i, 1, n) c[i] += c[i - 1];

    rep(i, 0, m)
    {
        int l = a[i].first;
        int r = a[i].second;
        l--, r--;
        int ones = c[r] - (l == 0 ? 0 : c[l - 1]);

        if (ones > (r - l + 1) - ones)
        {
            // cout << l << " " << r << " " << ones << endl;
            return true;
        }
    }
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<pi> a(m);
    rep(i, 0, m) cin >> a[i].first >> a[i].second;

    int q;
    cin >> q;

    vector<int> b(q);
    rep(i, 0, q) cin >> b[i];

    int l = 0;
    int r = q;

    // cout << check(a, b, 0, n) << endl;

    if (!check(a, b, q, n))
    {
        cout << -1 << endl;
        return;
    }

    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(a, b, mid, n))
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
    cin >> tc;
    while (tc--)
        solve();

    return 0;
}
