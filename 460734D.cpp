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

    map<int, int> starts, ends;
    starts[0] = -1;
    ends[0] = -1;

    int csum = 0;

    rep(i, 0, n)
    {
        cin >> a[i];
        csum = (csum + a[i]) % k;
        if (starts.find(csum) == starts.end())
            starts[csum] = i;
        ends[csum] = i;
    }

    int ans = -1;

    for (auto i : starts)
    {
        if (i.first == 0 && ends[i.first] == -1)
            continue;
        ans = max(ans, ends[i.first] - starts[i.first]);
    }

    if (ans == 0)
        ans = -1;

    cout << ans << endl;
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
