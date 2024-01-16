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
    int n, q;
    cin >> n >> q;

    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    vi pref = a;
    rep(i, 1, n)
    {
        pref[i] += pref[i - 1];
    }

    vi preff = pref;

    rep (i, 1, n)
    {
        preff[i] += preff[i - 1];
    }

    // preff is the prefix sum of pref
    // a1, 2a1 + a2, 3a1 + 2a2 + a3...

    while (q--)
    {
        int s, d, k;
        cin >> s >> d >> k;

    }



}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    while (tc--)
        solve();

    return 0;
}