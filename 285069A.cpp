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

pair<bool, pair<int, int>> check(vi &a, float mid, int d)
{
    int n = a.size();
    vi pref(n + 1, 0);
    vi minn(n + 1, 1e9);

    rep(i, 1, n + 1) pref[i] = a[i - 1] - mid + pref[i - 1];
    rep(i, 1, n + 1) minn[i] = min(pref[i], minn[i - 1]);

    rep(i, d, n + 1)
    {
        if (pref[i] >= minn[i - d])
            return {true, {i - d + 1, i}};
    }

    return {false, {-1, -1}};
}

void solve()
{
    int n, d;
    cin >> n >> d;

    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    float l = 0, r = 1e9;
    // cout << check(a, 0, d) << endl;
    // cout << check(a, 6.5, d) << endl;
    // cout << check(a, 7, d) << endl;
    pair<bool, pair<int, int>> f = check(a, 7, d);

    int aa = 0, b = 0;

    while (l + 1e-7 < r)
    {
        float mid = (l + r) / 2;
        f = check(a, mid, d);
        if (f.first)
        {
            aa = f.second.first;
            b = f.second.second;
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    cout << aa << " " << b << endl;
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
