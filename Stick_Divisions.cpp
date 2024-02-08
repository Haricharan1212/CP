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
    int n, x;
    cin >> x >> n;

    vi a(n);
    multiset <int> s;

    rep (i, 0, n) cin>> a[i], s.insert(a[i]);

    int ans = 0;

    while (s.size() > 1){
        int x = *s.begin();
        s.erase(s.begin());
        int y = *s.begin();
        s.erase(s.begin());
        ans += x + y;
        s.insert(x + y);
    
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