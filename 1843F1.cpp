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

    int cnt = 0;

    vi mincost(n + 1, 0);
    vi maxcost(n + 1, 0);
    vi sums(n + 1, 0);
    vi mini(n + 1, 0);
    vi maxi(n + 1, 0);

    mini[0] = 0;
    mincost[0] = 0;

    maxi[0] = 1;
    maxcost[0] = 1;
    sums[0] = 1;

    rep(i, 0, n)
    {
        char c;
        cin >> c;
        if (c == '+')
        {
            int a;
            cin >> a;
            a--;
            cnt++;
            int x;
            cin >> x;

            sums[cnt] = sums[a] + x;
            mini[cnt] = min(mini[a] + x, 0LL);
            mincost[cnt] = min(mincost[a], mini[cnt]);

            maxi[cnt] = max(maxi[a] + x, 0LL);
            maxcost[cnt] = max(maxcost[a], maxi[cnt]);
        }
        else
        {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            if (c >= mincost[b] && c <= maxcost[b])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
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
