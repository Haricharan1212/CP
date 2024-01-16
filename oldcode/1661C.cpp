// Haricharan

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define vi vector<int>
#define vii vector<vector<int>>
#define pi pair<int, int>
#define mi map<int, int>
#define si set<int>
#define rep(var, l, r) for (int var = l; var < r; var++)
#define repr(var, r, l) for (int var = r; var > l; var--)
int mod1 = 1000000007;
int mod2 = 998244353;

int check(int ht, vi &a)
{

    map<int, int> m;

    for (auto i : a)
    {
        int num = (ht - i) / 2;
        m[2] += num;
        m[(ht - i) % 2]++;
    }

    int x = m[2] - m[1];
    x *= 2;

    if (m[1] > m[2])
        return (m[1] - 1) * 2 + 1;
    else
        return 2 * m[1] + x / 3 * 2 + x % 3;
}

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    int mx = 0;
    rep(i, 0, n)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int ans = 1e18;

    ans = min(ans, check(mx, a));
    ans = min(ans, check(mx + 1, a));
    ans = min(ans, check(mx + 2, a));

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
