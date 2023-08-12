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

// a b a + b a + 2 b 2a + 3b 3a + 5b + ...

vi fibs;

void solve()
{
    int n, k;
    cin >> n >> k;

    // cout << fibs[k - 3] << ' ' << fibs[k - 2] << endl;

    // fibs[k - 3] a + fibs[k - 2] * b = n

    if (k > 46)
    {
        cout << 0 << endl;
        return;
    }

    int ans = 0;

    for (int a = 0; fibs[k - 3] * a + fibs[k - 2] <= n; a++)
    {
        int b = (n - fibs[k - 3] * a) / fibs[k - 2];
        if (fibs[k - 3] * a + fibs[k - 2] * b == n && a <= b)
        {
            // cout << a << ' ' << b << endl;
            ans++;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;

    fibs.push_back(1);
    fibs.push_back(1);
    int i = 2;
    while (fibs[i - 1] <= 1e10)
    {
        fibs.push_back(fibs[i - 1] + fibs[i - 2]);
        i++;
    }

    while (tc--)
        solve();

    return 0;
}
