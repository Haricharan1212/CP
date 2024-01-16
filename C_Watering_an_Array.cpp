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
    int n, k, d;
    cin >> n >> k >> d;

    vi a(n);

    rep(i, 0, n) cin >> a[i];

    vi v(k);
    rep(i, 0, k) cin >> v[i];

    int mxscore = 0;

    rep (i, 0, min(2 * n + 5, d)){        

        int num = v[i % k];

        int cscore = 0;
        rep (j, 0, n) if (a[j] == j + 1) cscore++;

        mxscore = max(mxscore, cscore + ((d - (i + 1))/2));
        // cout << cscore << " " << mxscore << endl;

        rep (j, 0, num) a[j]++;

    }

    cout <<  mxscore << endl;
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