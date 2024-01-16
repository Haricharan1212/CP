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

template <class T>
class DSU
{
public:
    vector<T> a;
    vector<int> parent;
    vector<int> sizes;

    function<T(T, T)> op;

    DSU(vector<T> a, function<T(T, T)> op = [](T a, T b){return a;})
    {
        int n = a.size();
        this->a = a;
        this->op = op;
        parent.resize(n);
        sizes.resize(n);
        rep(i, 0, n) parent[i] = i, sizes[i] = 1;
    }

    int findparent(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = findparent(parent[x]);
    }

    void un(int x, int y)
    {
        x = findparent(x);
        y = findparent(y);

        if (x != y)
        {
            if (sizes[x] < sizes[y])
                swap(x, y);

            sizes[x] += sizes[y];
            parent[x] = y;
            a[y] = op(a[x], a[y]);
        }
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector <pair <int, pi>> edges;

    rep(i, 0, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back({w, {u, v}});
    }

    sort(edges.begin(), edges.end());

    int ans = 0;

    DSU <int> dsu(vi(n, 0LL));

    rep (i, 0, m){
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;

        if (dsu.findparent(u) != dsu.findparent(v)){
            dsu.un(u, v);
            ans += w;
        }
    }

    cout << ans << "\n";
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