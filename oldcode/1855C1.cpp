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

    vi a(n);

    rep(i, 0, n)
    {
        cin >> a[i];
    }

    vector<pi> ans;

    rep(i, 0, n - 1)
    {
        if (a[i] <= a[i + 1])
            continue;

        else
        {
            int j = i + 1;
            if (a[i] < 0)
            {
                ans.push_back({i, j});
                a[i] += a[j];
            }
            else
            {
                ans.push_back({j, i});
                a[j] += a[i];
            }
        }
    }

    cout << ans.size() << endl;

    for (auto i : ans)
        cout << i.first + 1 << ' ' << i.second + 1 << endl;
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
