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

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    int sum = 0;
    rep(i, 0, n)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 3)
    {
        cout << 0 << endl;
        return;
    }
    int num = sum / 3;

    sum = 0;

    vector<int> v1, v2;

    rep(i, 0, n - 1)
    {
        sum += a[i];

        if (sum == num)
        {
            v1.push_back(i);
        }
        else if (sum == 2 * num)
        {
            v2.push_back(i);
        }
    }

    int ans = 0;

    if (num == 0)
    {
        cout << ((v1.size()) * (v1.size() + 1)) / 2 << endl;
        return;
    }

    rep(i, 0, v1.size())
    {
        ans += v2.end() - upper_bound(v2.begin(), v2.end(), v1[i]);
    }

    cout << ans;
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
