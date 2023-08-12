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

    vi a(n);

    vi c(n);

    rep(i, 0, n)
    {
        cin >> c[i];
        c[i]--;
        a[c[i]] = i;
    }

    int cnt = 0;
    rep(i, 0, n)
    {
        if (i == 0 || a[i] < a[i - 1])
            cnt++;
    }

    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;

        swap(c[x], c[y]);

        x = c[x], y = c[y];

        if (x && a[x] < a[x - 1])
            cnt--;
        if (x != n - 1 && a[x] > a[x + 1])
            cnt--;

        if (y && a[y] < a[y - 1])
            cnt--;
        if (y != n - 1 && a[y] > a[y + 1])
            cnt--;

        swap(a[x], a[y]);

        if (x && a[x] < a[x - 1])
            cnt++;
        if (x != n - 1 && a[x] > a[x + 1])
            cnt++;

        if (y && a[y] < a[y - 1])
            cnt++;
        if (y != n - 1 && a[y] > a[y + 1])
            cnt++;

        cout << cnt << endl;

        for (auto i : a)
            cout << i << ' ';
        cout << endl;
        for (auto i : c)
            cout << i << ' ';
        cout << endl;
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
