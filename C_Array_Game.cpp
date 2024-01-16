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
    int n, k;
    cin >> n >> k;

    vi a(n);
    rep (i, 0, n)
        cin >> a[i];

    if (k >= 3){
        cout << 0 << endl;
        return;
    }

    if (k == 1){
        int ans = 1e18;

        rep (i, 0, n)
            rep (j, 0, i) ans = min(ans, abs(a[i] - a[j]));

        rep (i, 0, n) ans = min(ans, a[i]);

        cout << ans << endl;
        return;
    }
    else if (k == 2){
        si curr;
        set <int, greater<int>> curr2;
        rep (i, 0, n) curr.insert(a[i]), curr2.insert(a[i]);
        
        int ans = 1e18;

        rep (i, 0, n) rep (j, 0, i){
            int num = abs(a[i] - a[j]);
            ans = min(ans, a[i]);
            ans = min(ans, num);

            if (curr.lower_bound(num) != curr.end()) ans = min(ans, *curr.lower_bound(num) - num);
            if (curr2.lower_bound(num) != curr2.end()) ans = min(ans, num - *curr2.lower_bound(num) );

            // cout << ans << endl;

        }

        cout << ans << endl;
    }

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