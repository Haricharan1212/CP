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
    vi sizes, mins, maxs;
    DSU(int n)
    {
        a = vector<int>(n);
        sizes = vector<int>(n, 1);
        mins = vector<int>(n);
        maxs = vector<int>(n);
        rep(i, 0, n) a[i] = i, mins[i] = i, maxs[i] = i;
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
            sizes[y] += sizes[x];
            mins[y] = min(mins[y], mins[x]);
            maxs[y] = max(maxs[y], maxs[x]);
        }
    }

    vi getsize(int x)
    {
        int f = find(x);
        return {mins[f], maxs[f], sizes[f]};
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

        if (s == "union")
        {
            cin >> x >> y;
            x--, y--;
            d.un(x, y);
        }
        else
        {
            cin >> x;
            x--;
            // cout << x << ' ';

            auto f = d.getsize(x);
            cout << f[0] + 1 << ' ' << f[1] + 1 << ' ' << f[2] << '\n';
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
