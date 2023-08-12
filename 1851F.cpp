// Haricharan
#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define vb vector<bool>
#define pi pair<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)

// 3, 1-> 1101 = 13

// bitwise xor should be as small as possible

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pi> a(n);
    rep(i, 0, n)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    int ans = 1e10;
    // cout << ans;

    int ind = -1;
    rep(i, 0, n - 1)
    {
        if ((a[i].first ^ a[i + 1].first) < ans)
        {
            ans = a[i].first ^ a[i + 1].first;
            ind = i;
        }
    }

    bitset<32> b(a[ind].first), c(a[ind + 1].first);

    int anss = 0;
    for (int i = 0; i < k; i++)
    {
        if (b[i] == c[i] && c[i] == 0)
        {
            anss += (1 << i);
        }
    }

    cout << a[ind].second + 1 << " " << a[ind + 1].second + 1 << ' ' << anss << endl;
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
