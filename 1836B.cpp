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

    int n, k, g;
    cin >> n >> k >> g;

    if (k == 0)
    {
        cout << 0 << endl;
        return;
    }

    int f = (g - 1) / 2;

    if (f * n >= k * g)
    {
        cout << k * g << endl;
        return;
    }

    int num = k * g - (n - 1) * (f);

    int ans = 0;

    if (num % g >= f + 1)
        ans += num + g - num % g;
    else
        ans += num - (num % g);

    ans = k * g - ans;

    cout << ans << endl;
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
