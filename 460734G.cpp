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
    int n, m;
    cin >> n >> m;

    vi pos(n);

    rep(i, 0, n)
    {
        int x;
        cin >> x;
        x--;
        pos[x] = i;
    }

    int midpos = (n - 1) / 2;
    vi poss = pos;

    rep(i, 0, n / 2)
    {
        int pos = poss[i];
        poss[i] = (midpos + (2 * m - pos)) % n;
    }

    rep(i, n / 2, n)
    {
        int pos = n - 1 - poss[i];
        poss[i] = (midpos + (2 * m - pos) + 1) % n;
    }

    vi ans(n, -2);

    rep(i, 0, n) ans[poss[i]] = i;

    rep(i, 0, n) cout << ans[i] + 1 << " ";
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
