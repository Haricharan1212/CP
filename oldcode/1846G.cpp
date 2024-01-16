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

struct med
{
    string a;
    string b;
    int d;
};

bool check(string &a, string &b)
{
    rep(i, 0, a.size())
    {
        if (a[i] < b[i])
            return false;
    }
    return true;
}

void dfs(vii &adj, int node, vector<med> &meds, int &ans, int curr, string &s, vb &vis)
{
    vis[node] = true;

    cout << node << ' ';

    if (node)
        if (check(meds[node - 1].b, s))
        {
            ans = min(ans, curr + meds[node].d);
            return;
        }

    for (auto i : adj[node])
        if (vis[i] == false)
            dfs(adj, i, meds, ans, curr + (node == 0 ? 0 : meds[node - 1].d), s, vis);
}

void solve()
{
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;
    vector<med> meds(m);
    rep(i, 0, m)
    {
        cin >> meds[i].d >> meds[i].a >> meds[i].b;
    }
    vii adj(m + 1);
    string temp = s;
    rep(i, 0, temp.size()) temp[i] = '0';

    rep(i, 0, m)
    {
        if (check(temp, meds[i].b))
            adj[0].push_back(i + 1);

        rep(j, 0, m)
        {
            if (check(meds[i].a, meds[j].b))
                adj[i + 1].push_back(j + 1);
        }
    }

    int ans = 1e18;
    int curr = 0;
    vb vis(m + 1, false);
    dfs(adj, 0, meds, ans, curr, s, vis);

    cout << ans << endl;
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
