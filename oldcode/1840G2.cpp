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

    int mm = start;

    int a = 2;
    rep(i, 0, a)
    {
        int num = rand() % 1000000;
        cout << "+ " << num << endl;
        int x;
        cin >> x;
        mm = max(mm, x);
    }

    vi f = {mm};
    map<int, int> m;
    m[mm] = 0;
    int mx = 3;

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
