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

    int arr[n][m];

    rep(i, 0, n)
    {
        string s;
        cin >> s;
        rep(j, 0, m)
        {
            arr[i][j] = s[j] == '#' ? 1 : 0;
        }
    }

    rep(i, 0, n)
    {
        int cnt = 0;
        rep(j, 0, m) cnt += arr[i][j];

        if (cnt == 0)
        {
            cout << -1 << endl;
            return;
        }
    }

    rep(j, 0, m)
    {
        int cnt = 0;
        rep(i, 0, n) cnt += arr[i][j];

        if (cnt == 0)
        {
            cout << -1 << endl;
            return;
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
