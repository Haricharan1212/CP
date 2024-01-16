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

    vii adj(n);
    map<pi, int> mm;
    rep(i, 0, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        adj[a].push_back(b);
        adj[b].push_back(a);

        int c;
        cin >> c;

        mm[{a, b}] = c;
        mm[{b, a}] = c;
    }

    vi dist(n, INT_MAX);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
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
