// Haricharan
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define int long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define vb vector<bool>
#define pi pair<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)

#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    int csum = 0;
    ordered_set s;
    rep(i, 0, k) s.insert(a[i]), csum += a[i];

    int mid = (k + 1) / 2 - 1;

    rep(i, k, n)
    {
        s.erase(s.find_by_order(s.order_of_key(a[i - k])));
        s.insert(a[i]);
        cout << *s.find_by_order(mid) << ' ';
    }
    cout << '\n';
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
