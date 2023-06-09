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

    int start;
    cin >> start;

    vi f = {start};
    map<int, int> m;
    m[start] = 0;
    int mx = 1005;
    rep(i, 1, mx)
    {
        cout << "+ " << 1 << endl;
        int x;
        cin >> x;
        f.push_back(x);

        if (m.find(x) != m.end())
        {
            cout << "! " << i << endl;
            return;
        }
        m[x] = i;
    }

    rep(i, 1, mx + 2)
    {
        cout << "+ " << mx << endl;

        int x;
        cin >> x;

        if (m.find(x) != m.end())
        {
            cout << "! " << mx - m[x] - 1 + (i)*mx << endl;
            return;
        }
    }

    cout << "! 1000000" << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();

    return 0;
}
