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
    int ts, tf, t, n;
    cin >> ts >> tf >> t >> n;

    multiset<int> a;
    vi b(n);
    rep(i, 0, n)
    {
        cin >> b[i];
        a.insert(b[i]);
    }

    int ctime = ts;
    deque<int> q;

    rep(i, 0, n)
    {
        if (b[i] < ctime)
            q.push_back(b[i]);
    }
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
