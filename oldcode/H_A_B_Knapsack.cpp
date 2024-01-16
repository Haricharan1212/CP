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
    int n, m, s, A, B;
    cin >> n >> m >> s >> A >> B;

    vi a(n), b(m);

    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    rep (i, 1, n) a[i] += a[i - 1];
    rep (i, 1, m) b[i] += b[i - 1];

    int ans = 0;

    rep (i, 0, n){
        // i + 1 a items
        int cweight = A * (i + 1);
        if (cweight > s) break;
        int maxind = (s - cweight) / B;

        ans = max(ans, a[i] + (maxind == 0? 0: b[min(maxind - 1, m - 1)]));
    }

    // 0 a items

    if (s / B > 0)
        ans = max(ans, b[min(m - 1, s / B - 1)]);


    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //cin >> tc;
    while (tc--)
        solve();

    return 0;
}