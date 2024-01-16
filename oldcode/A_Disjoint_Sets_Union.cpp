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
    function<T(T, T)> op;

    DSU(vector<T> a, function<T(T, T)> op)
    {
        int n = a.size();
        this->a = a;
        this->op = op;
        parent.resize(n);
        rep(i, 0, n) parent[i] = i;
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
            parent[x] = y;
            a[y] = op(a[x], a[y]);
        }
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vi a(n);
    rep(i, 0, n) a[i] = i;

    DSU<int> dsu(a, [](int x, int y)
                 { return x + y; });

    rep(i, 0, m)
    {
        string t;
        cin >> t;
        if (t == "union")
        {
            int x, y;
            cin >> x >> y;
            x--, y--;
            dsu.un(x, y);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            
            cout << ((dsu.findparent(l) == dsu.findparent(r)) ? "YES" : "NO") << "\n";
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    // precomp(10);

    while (tc--)
        solve();

    return 0;
}