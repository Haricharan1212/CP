// Haricharan
#include <bits/stdc++.h>
using namespace std;

// #define int long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define vb vector<bool>
#define pi pair<int, int>
#define rep(var, l, r) for (int var = l; var < r; var++)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

void solve()
{
    int n, k;
    cin >> n >> k;

    vi a(n);
    ordered_set s;

    rep(i, 0, n)
    {
        int x;
        cin >> x;
        a[i] = x;

        s.insert(x);
    }

    int cnt = 0;
    rep(i, 0, n)
    {
        cnt += s.order_of_key(a[i]);
        s.erase(s.find(a[i]));
    }

    cout << cnt << endl;
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
