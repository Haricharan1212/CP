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
    int n, m, k;
    cin >> n >> m >> k;

    vector <pi> a(m);

    rep(i, 0, m){
        cin >> a[i].first >> a[i].second;
    
    }

    vector <pair<string, pi>> ans(k);

    rep (i, 0, k){
        string s;
        int a, b;
        cin >> s >> a >> b;
        ans[i] = {s, {a, b}};
    }

    vi b(n, 0);
    DSU <int> dsu(b);

    vector <string> anss(k);

    while (k--){
        if (ans[k].first == "cut"){
            dsu.un(ans[k].second.first - 1, ans[k].second.second - 1);
        }
        else{
            int x = dsu.findparent(ans[k].second.first - 1);
            int y = dsu.findparent(ans[k].second.second - 1);

            if (x != y){
                anss[k] = "NO\n";
            }
            else{
                anss[k] = "YES\n";
            }
        }
    }

    for (auto i : anss){
        cout << i;
    }

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