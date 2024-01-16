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

bool poss(int n, int x, int y)
{
    if (x <= n && x >= 1 && y <= n && y >= 1)
        return true;
    return false;
}

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;

    vi mxs;

    rep(i, 2, 10)
    {
        mxs.push_back(i);
    }

    for (auto mx : mxs)
    {
        set<pi> vals;
        int cnt = 0;

        rep(i, 0, mx + 1)
        {

            if (poss(n, x + i, y + mx - i))
                cnt++, vals.insert({x + i, y + mx - i});
            if (poss(n, x - i, y + mx - i))
                cnt++, vals.insert({x - i, y + mx - i});
            if (poss(n, x + i, y - mx + i))
                cnt++, vals.insert({x + i, y - mx + i});
            if (poss(n, x - i, y - mx + i))
                cnt++, vals.insert({x - i, y - mx + i});
        }
        if (vals.size() >= 9)
        {
            cout << "YES" << endl;
            return;
        }
    }

    if (x + 3 <= n && x - 3 >= 1 && y + 3 <= n && y - 3 >= 1)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;

    // for (auto i : vals)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }

    // cout << vals.size();
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
