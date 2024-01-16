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

    int l = 1;
    int r = n * n;

    while (l < r)
    {
        int mid = (l + r) / 2;
        int cnt = 0;
        rep(i, 1, n + 1)
        {
            cnt += min(n, mid / i);
        }

        if (cnt >= k)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << l << ' ';
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
