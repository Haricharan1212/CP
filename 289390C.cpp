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

class DSU
{
public:
    vi a;
    vi exp;
    DSU(int n)
    {
        a = vector<int>(n);
        exp = vector<int>(n, 0);
        rep(i, 0, n) a[i] = i;
    }

    int find(int x)
    {
        if (a[x] == x)
            return x;
        return a[x] = find(a[x]);
    }

    void un(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x != y)
        {
            a[x] = y;
        }
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    auto d = DSU(n);
    rep(i, 0, m)
    {
        string s;
        int x, y;

        cin >> s;

        if (s == "join")
        {
            cin >> x >> y;
            x--, y--;
            d.un(x, y);
        }
        else if (s == "get")
        {
            cin >> x;
            x--;
            cout << d.exp[d.find(x)] << "\n";
        }
        else
        {
            cin >> x >> y;
            x--;
            int f = d.find(x);
            d.exp[f] += y;
        }
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
