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

    vi a(n, 0);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    multiset<int> s;
    int rcurr = 0;
    s.insert(rcurr);
    for (int i = n - 1; i >= 0; i--)
    {
        rcurr += a[i];
        s.insert(rcurr);
    }

    int k = 0;
    int lcurr = 0;
    int mxans = *s.rbegin();

    rep(i, 0, n)
    {
        lcurr += a[i];
        s.erase(s.find(rcurr));
        rcurr -= a[i];
        int num = *s.rbegin();

        int ans = lcurr + num;

        // cout << ans << ' ';
        if (ans > mxans)
        {
            mxans = ans;
            k = lcurr;
        }
    }

    cout << k << endl;
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
