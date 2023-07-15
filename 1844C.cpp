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

int mxsum(vi &a)
{
    int size = a.size();
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] > 0)
            ans += a[i];
    }

    return ans;
}
void solve()
{
    int n;
    cin >> n;

    vi a(n);
    int mx = -1e18;

    rep(i, 0, n)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    if (mx <= 0)
    {
        cout << mx << endl;
        return;
    }

    vi b, c;

    rep(i, 0, n)
    {
        if (i % 2 == 0)
        {
            b.push_back(a[i]);
        }
        else
        {
            c.push_back(a[i]);
        }
    }

    cout << max(mxsum(b), mxsum(c)) << endl;
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
