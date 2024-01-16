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

    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int x;
    cin >> x;
    
    vi dp(n, 0);
    dp[0] = 1;

    rep (i, 1, n){  
        dp[i] = max((i == 1? 0: dp[i - 2]), dp[i - 1] + ((a[i] + a[i - 1]) >= 2 * x ? 1 : 0));
    }

    cout << dp[n - 1] << endl;
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