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

    vi a(n - 1);
    rep(i, 0, n - 1) cin >> a[i];

    multiset<int> s;

    rep(i, 0, n - 2) s.insert(a[i + 1] - a[i]);
    s.insert(a[0]);

    vi nn;
    rep(i, 1, n + 1)
    {
        if (s.count(i) == 0)
            nn.push_back(i);
        if (s.find(i) != s.end())
            s.erase(s.find(i));
    }

    int f = accumulate(nn.begin(), nn.end(), 0LL);
    if (s.find(f) != s.end())
        s.erase(s.find(f));

    if ((int)nn.size() > 2 || s.size())
    {
        cout << "NO" << endl;
        return;
    }
    else
    {
        cout << "YES" << endl;
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
