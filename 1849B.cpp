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
    set<pi> s;
    int n, k;
    cin >> n >> k;

    map<int, vector<int>, greater<int>> m;

    rep(i, 0, n)
    {
        int x;
        cin >> x;

        m[x % k].push_back(i);
    }

    for (auto j : m[0])
        cout << j + 1 << " ";

    for (auto i : m)
    {
        if (!i.first)
            continue;
        for (auto j : i.second)
            cout << j + 1 << " ";
    }

    cout << endl;
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
