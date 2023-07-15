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
    int n;
    cin >> n;

    int f = n + 1;

    rep(i, 0, n) if (n % (i + 1) != 0)
    {
        f = i + 1;
        break;
    }

    int cnt = 0;
    vi ans(n);

    rep(i, 0, f) ans[i] = i;
    rep(i, f, n) ans[i] = ans[i - f];

    rep(i, 0, n) cout << (char)(ans[i] + 'a');
    cout << endl;
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
