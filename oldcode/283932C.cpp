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

bool check(int n, int x, int y, int t)
{

    int f = 0;
    if (t < x)
        f = 0;
    else
    {
        t -= x;
        f = 1;

        f += t / x + t / y;
    }

    return f >= n;
}

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;

    if (x > y)
        swap(x, y);

    int l = 0, r = 1e10 + 5;

    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(n, x, y, mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << l << endl;
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
