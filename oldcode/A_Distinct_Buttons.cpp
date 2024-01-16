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
    
    vector <pi> a(n);

    rep (i, 0, n) cin >> a[i].first >> a[i].second;

    int up = 0;
    int down = 0;
    int left = 0;
    int right = 0;

    rep (i, 0, n){
        if (a[i].first > 0) right = 1;
        else if (a[i].first < 0) left = 1;

        if (a[i].second > 0) up = 1;
        else if (a[i].second < 0) down = 1;
    }

    if (up + down + left + right < 4){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

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