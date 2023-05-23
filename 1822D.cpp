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

//

void solve()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    else if (((n * (n + 1)) / 2) % n == 0)
    {
        cout << -1 << endl;
        return;
    }

    // 0 5 1 4 2 3

    vi a(n);
    int count = n - 1;
    for (int i = 1; i < n; i += 2)
    {
        a[i] = count--;
    }
    count = 0;
    for (int i = 0; i < n; i += 2)
    {
        a[i] = count++;
    }

    vi ans(n);
    int sum = 0;

    rep(i, 0, n)
    {
        if (i == 0)
        {
            ans[0] = n;
            sum += n;
            continue;
        }

        ans[i] = ((a[i] - sum) % n + n) % n;

        sum += ans[i];
    }

    for (auto i : ans)
        cout << i << " ";
    cout << endl;
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
