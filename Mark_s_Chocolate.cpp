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
    int n, l;
    cin >> n >> l;

    int ans = 1;
    int curr = 1;

    while (l > 0)
    {
        if (l % 2 == 1)
        {
            break;
        }
        else
        {
            l /= 2;
            ans *= 2;
        }
    }

    if (ans >= n)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
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
