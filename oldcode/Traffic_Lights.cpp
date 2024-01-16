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

    multiset<int> s;
    s.insert(n);
    si c = {0, n};
    set<int, greater<int>> cc = {0, n};
    rep(i, 0, k)
    {
        int x;
        cin >> x;
        int r = *c.lower_bound(x);
        int l = *cc.lower_bound(x);

        c.insert(x);
        cc.insert(x);

        s.erase(s.find(r - l));
        s.insert(x - l);
        s.insert(r - x);

        cout << *s.rbegin() << " ";
    }
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
