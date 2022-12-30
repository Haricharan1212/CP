// Haricharan

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
typedef long long ll;

// For ordered Tree
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define vi vector<int>
#define vii vector<vector<int>>

bool check(vector<vector<ll>> arr, int l, int n, int m)
{
    vector<vector<ll>> pref = arr;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                pref[i][j] = 0;
            else
                pref[i][j] = (arr[i][j] >= l ? 1 : 0) + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }

    // cout << l;

    // for (auto i : pref)
    // {
    //     for (auto j : i)
    //         cout << j << ' ';
    //     cout << endl;
    // }

    for (int i = 0; i <= n - l; i++)
        for (int j = 0; j <= m - l; j++)
        {
            if ((pref[i + l][j + l] + pref[i][j] - pref[i][j + l] - pref[i + l][j]) == l * l)
                return true;
        }

    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> arr(n + 1, vector<ll>(m + 1, 0));

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                arr[i][j] = 0;
            else
                cin >> arr[i][j];
        }

    int l = 0, r = min(n, m);
    int mid;
    int ans = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (check(arr, mid, n, m))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    cout << ans << endl;
}

int main()
{
    fio;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
