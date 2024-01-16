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

// ordered set
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

void solve()
{
    int n;
    cin >> n;

    vector <pi> a(n);
    vector <int> healths(n);
    
    rep (i, 0, n) cin >> a[i].first;
    rep (i, 0, n) cin >> a[i].second, healths[i] = a[i].second;

    sort(healths.begin(), healths.end());
    for (int i = 0; i < n; i++) healths[i] += (i > 0 ? healths[i - 1] : 0);

   map <int, int> s;


    for (int i = 0; i < n; i++){
        int idx = (upper_bound(healths.begin(), healths.end(), a[i].first) - healths.begin());
        s[idx]++;

        cout << idx << ' ';
    }

    int ans = 0;

    int ext = 0;

    s[n - 1] += s[n];

    for (int i = n - 1; i >= 0; i--){        
        ext += s[i];
        cout << ext << '-';
        if (ext >= n - i - 1) ans++;
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