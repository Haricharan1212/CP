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

vector<pi> parent;
int cnt;

void make_set(int v)
{
    parent[v] = {v, 1};
}

pi find_set(int v)
{
    if (v == parent[v].first)
        return parent[v];
    return parent[v] = find_set(parent[v].first);
}

void union_sets(int a, int b)
{
    a = find_set(a).first;
    b = find_set(b).first;

    if (a != b)
        parent[b] = {a, find_set(a).second + find_set(b).second}, cnt--;

    find_set(a);
    find_set(b);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    cnt = n;

    parent = vector<pi>(n);

    rep(i, 0, n) make_set(i);

    rep(_, 0, m)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        if (find_set(u) != find_set(v))
            union_sets(u, v);

        cout << cnt << endl;
    }

    rep(i, 0, n) cout << parent[i].first << ' ' << parent[i].second << endl;
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
