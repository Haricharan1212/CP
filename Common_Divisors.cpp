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
    const int mxx = 1e6;

    int n;
    cin >> n;

    int arr[mxx + 5] = {0};

    rep(i, 0, n)
    {
        int x;
        cin >> x;
        arr[x]++;
    }

    int mx = 1;

    rep(i, 1, mxx + 1)
    {
        int cnt = 0;

        rep(j, 1, mxx / i + 2)
        {
            if (i * j <= mxx)
                cnt += arr[i * j];
        }

        if (cnt >= 2)
            mx = max(i, mx);
    }

    cout << mx << endl;
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
