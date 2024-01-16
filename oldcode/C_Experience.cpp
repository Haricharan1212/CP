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

    int find(int x){
        // cout << parent[x] << ' ';
        int ans = a[x].points;

        while (parent[x] != x)
            x = parent[x], ans += a[x].points;

        return ans;
    }

    void un(int x, int y)
    {
        x = findparent(x);
        y = findparent(y);

        if (x != y)
        {
            parent[x] = y;
        }
    }
};

struct Node {
    int points = 0;
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector <Node> a(n);

    DSU<Node> dsu(a, [](Node x, Node y)
                 { return y; });

    rep (i, 0, m){
        string s;
        cin >> s;

        if (s == "join"){
            int l, r;
            cin >> l >> r;
            l--, r--;
            dsu.un(l, r);
        }
        else if (s == "get"){
            int x;
            cin >> x;
            x--;
            cout << dsu.find(x) << "\n";
        }
        else if (s == "add"){
            int x, y;
            cin >> x >> y;
            x--;
            dsu.a[dsu.findparent(x)].points += y;
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