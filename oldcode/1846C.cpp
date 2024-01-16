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
    int n, m, h;
    cin >> n >> m >> h;

    vector<pair<pi, int>> ans;

    rep(i, 0, n)
    {
        vi a(m);

        rep(j, 0, m) cin >> a[j];
        sort(a.begin(), a.end());

        int sum = 0;
        int cnt = 0;
        int pen = 0;

        rep(j, 0, m)
        {
            if (sum + a[j] <= h)
                sum += a[j], cnt++, pen += sum;
            else
                break;
        }

        // cout << cnt << ' ' << pen << endl;

        ans.push_back({{cnt, -pen}, -(i + 1)});
    }

    sort(ans.begin(), ans.end(), greater<pair<pi, int>>());

    rep(i, 0, n)
    {
        if (ans[i].second == -(1))
        {
            cout << i + 1 << endl;
            return;
        }
    }
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
