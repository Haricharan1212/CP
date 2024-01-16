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
    cin >> n, m;
    vector<vector<int>> v(m, vector<int>(3, 0));

    rep(i, 0, m) cin >> v[i][0] >> v[i][1] >> v[i][2];

    vii adj(n);

    rep(i, 0, m)
    {
        if (v[i][0] == 1)
        {
            adj[v[i][1] - 1].push_back(v[i][2] - 1);
            adj[v[i][2] - 1].push_back(v[i][1] - 1);
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
