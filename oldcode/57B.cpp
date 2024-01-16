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
    int n, m, k;
    cin >> n >> m >> k;

    int arr[n + 5] = {0};
    int arrr[n + 5] = {0};

    rep(i, 0, m)
    {
        int l, r, x;
        cin >> l >> r >> x;

        arr[l + 1]++;
        arr[r + 1]--;
        arrr[l] += x;
        arrr[r + 1] += -(x + r - l);
    }

    rep(i, 1, n + 1) arrr[i] += arrr[i - 1];

    // for (int i = 0; i <= n + 1; i++)
    //     cout << arr[i] << ' ';
    // cout << endl;

    // for (int i = 0; i <= n + 1; i++)
    //     cout << arrr[i] << ' ';
    // cout << endl;

    rep(i, 1, n + 5) arr[i] += arr[i - 1];
    // for (int i = 0; i <= n + 1; i++)
    //     cout << arr[i] << ' ';
    // cout << endl;
    rep(i, 1, n + 5) arr[i] += arr[i - 1];

    // for (int i = 0; i <= n + 1; i++)
    //     cout << arr[i] + arrr[i] << ' ';
    // cout << endl;

    int ans = 0;

    rep(i, 0, k)
    {
        int x;
        cin >> x;

        ans += arr[x] + arrr[x];
    }

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
