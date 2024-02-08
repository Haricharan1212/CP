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

// 22 42 40 28 29 27 25 56
// 42 40 28 29 27 25


void solve()
{
    int n, k;
    cin >> n >> k;

    vi a(n);

    int maxval = 0;
    vi maxindices = {};

    rep (i, 0, n){
        cin >> a[i];        
    }

    rep (i, 0, n){
        if (a[i] > maxval) {
            maxval = a[i];
            maxindices = {i};
        }
        else if (a[i] == maxval) {
            maxindices.push_back(i);
        }
    }

    vi b = a;
    sort(b.begin(), b.end(), greater<int>());
    int ans = -1e18;

    rep (i, 0, n){
        a[i] -= k * (i + 1);

        if (maxindices.size() >= 2){
            ans = max(ans, a[i] + maxval);
        }
        else{
            if (i == maxindices[0]) ans = max(ans, a[i] + b[1]);
            else ans = max(ans, a[i] + maxval);
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
    while (tc--)
        solve();

    return 0;
}