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

bool check(vector<pi> &a, int mid, int k)
{
    int n = a.size();
    int cnt = 0;
    rep(i, 0, n)
    {
        cnt += max(0LL, min(a[i].second, mid) - a[i].first + 1);
    }
    cnt--;

    return cnt >= k;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<pi> a(n);
    rep(i, 0, n)
    {
        cin >> a[i].first >> a[i].second;
    }

    int l = -1e10, r = 1e10;

    // cout << check(a, 6, k) << endl;

    while (l < r)
    {
        int mid = (l + r);
        if (mid >= 0)
            mid /= 2;
        else
            mid = (mid - 1) / 2;
        if (check(a, mid, k)) // check if mid is possible
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << l << endl;
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
