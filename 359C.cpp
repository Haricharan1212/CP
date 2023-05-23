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

int modexp(int x, int n, int mod)
{
    int res = 1;
    while (n)
    {
        if (n & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

void solve()
{
    int n, x;
    cin >> n >> x;

    vi a(n);
    int sum = 0;
    rep(i, 0, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());

    int cnt = 0;

    map<int, int> m;

    int ans = sum - a[n - 1];

    rep(i, 0, n) m[a[i] - a[0]]++;

    cout << modexp(3, 13, mod1) << endl;

    int xx = 1;

    for (auto i : m)
    {
        // cout << i.first << ' ' << i.second << endl;
        if (i.second % x == 0)
        {
            ans++;
            xx *= x;

            if (m[i.first + 1] % xx == 0)
            {
                m[i.first + 1] /= xx;
                m[i.first + 1] += i.second / x;
            }
            else
                break;
        }
        else
            break;
    }

    ans = min(ans, sum);
    ans = modexp(x, ans, mod1);
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
