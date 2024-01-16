// Haricharan
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

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

    vector <int> a(n);
    rep (i, 0, n) cin >> a[i];

    vi ans(n, 0);

    ordered_set s;
    rep(i, 0, n) s.insert(i + 1);   

    for (int i = n - 1; i >= 0; i--){
        int num = i + 1 - a[i];
        // cout << num << 'f';

        ans[i] = *s.find_by_order(num - 1);
        s.erase(ans[i]);
    }

    for (auto i: ans) cout << i << ' ';
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