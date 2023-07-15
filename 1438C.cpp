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

void print(vii &a)
{

    rep(i, 0, a.size())
    {
        rep(j, 0, a[0].size())
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cin >> a[i][j];
        }
    }

    vii b = a;

    rep(i, 0, n)
        rep(j, 0, m) if ((i + j + b[i][j]) % 2 == 1) b[i][j]++;

    print(b);
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
