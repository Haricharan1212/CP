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

bool check(vector<pi> &a, float mid)
{
    int n = a.size();

    float lmax = -1e18;
    float rmin = 1e18;

    rep(i, 0, n)
    {
        lmax = max(lmax, a[i].first - mid * a[i].second);
        rmin = min(rmin, a[i].first + mid * a[i].second);
    }
    if (lmax < rmin)
        return true;
    else
        return false;
}

void solve()
{
    int n;
    cin >> n;

    vector<pi> a(n);
    rep(i, 0, n) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());

    float l = 0, r = 1e9 + 1;

    while (l + 1e-8 < r)
    {
        float mid = (l + r) / 2.0;

        if (check(a, mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }

    cout << fixed << setprecision(30) << l << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //    cin >> tc;
    while (tc--)
        solve();

    return 0;
}
