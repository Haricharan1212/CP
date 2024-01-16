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

    int s;
    cin >> s;

    vector <int> a(n);
    rep (i, 0, n) cin >> a[i];

    int ans = 1e9;
    vi dp(s + 1, 0);
    dp[0] = 1;

    int l = 0;

    rep (r, 0, n){
        rep (i, 0, s + 1){
            if (dp[i]){
                cout << i << '-' << dp[i] << ' ';
            }
        }
        cout << endl;

        int num = a[r];            

        for (int i = s; i >= num; i--){
            dp[i] += dp[i - num];
        }

        if (dp[s] == 0) continue;

        while (dp[s] && l <= r){
            int num = a[l];

            for (int i = s; i >= num; i--)
                dp[i] -= dp[i - num];

            l++;
        }

        ans = min(ans, r - (l - 1) + 1);
    }

    cout << ans << endl;
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