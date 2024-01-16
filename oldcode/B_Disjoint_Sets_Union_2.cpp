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

struct Node{
    int size, mx, mn;
    // Node(int size, int mx, int mn){
    //     this->size = size;
    //     this->mx = mx;
    //     this->mn = mn;
    // }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector <Node> a(n);
    rep(i, 0, n) a[i].size = 1, a[i].mx = i + 1, a[i].mn = i + 1;

    DSU<Node> dsu(a, [](Node x, Node y){
        Node node;
        node.size = x.size + y.size;
        node.mx = max(x.mx, y.mx);
        node.mn = min(x.mn, y.mn);
        return node;
    });

    rep (i, 0, m){
        string t;
        cin >> t;

        if (t == "union"){
            int x, y;
            cin >> x >> y;
            x--, y--;
            dsu.un(x, y);
        }
        else{
            int x;
            cin >> x;
            x--;
            Node res = dsu.a[dsu.findparent(x)];
            cout << res.mn << ' ' << res.mx << ' ' << res.size << "\n";
        }
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