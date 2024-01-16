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

bool check(vi &a, int mid, int k)
{
    int current = a[0];
    int num = 1;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] - current < mid)
        {
        }
        else
        {
            num++;
            current = a[i];
        }
    }

    return num >= k;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int l = 1;
    int r = a[n - 1] - a[0];

    while (l < r)
    {
        int mid = (l + r + 1) / 2;

        if (check(a, mid, k))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
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
