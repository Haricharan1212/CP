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
#define float long double

void solve()
{
    float n, k;
    cin >> n >> k;

    float ans = 0;

    rep(i, 1, k + 1)
    {
        float x = i / k;
        float y = (i - 1) / k;
        ans += (powl(x, n) - powl(y, n)) * i;

        // cout << ans << ' ';
    }

    float value = llround(ans * 1e6) / 1e6;

    cout << fixed << setprecision(6) << value << endl;
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
