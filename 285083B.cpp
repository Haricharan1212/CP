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
    int n = a.size();

    int current = 0;
    int num = 1;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > mid)
            return false;

        if (current + a[i] <= mid)
        {
            current += a[i];
        }
        else
        {
            num++;
            current = a[i];
        }
    }

    return num <= k;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int l = 0;
    int r = accumulate(a.begin(), a.end(), 0LL);

    while (l < r)
    {
        int mid = (l + r) / 2;

        if (check(a, mid, k))
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
