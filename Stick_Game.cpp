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
    int n, k;
    cin >> n >> k;

    vi a(k);
    rep(i, 0, k)
    {
        cin >> a[i];
    }

    vb arr(n + 1, false);

    rep(i, 1, n + 1)
    {
        for (auto j : a)
            if (i - j >= 0)
                if (arr[i - j] == false)
                    arr[i] = true;
    }

    rep(i, 1, n + 1)
    {
        cout << (arr[i] ? 'W' : 'L');
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
