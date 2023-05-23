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

// #define int long long int
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

int n, m;

void check(vii &arr, int &sum, int ii, int jj, vector<vector<bool>> &visited)
{

    sum += arr[ii][jj];
    visited[ii][jj] = true;
    vector<pi> adj;

    vi is = {1, -1, 0, 0};
    vi js = {0, 0, -1, 1};

    for (int ind = 0; ind <= 3; ind += 1)
    {
        int i = is[ind];
        int j = js[ind];
        {
            if (ii + i >= 0 && ii + i < n && jj + j >= 0 && jj + j < m)
            {
                if (arr[ii + i][jj + j])
                    adj.push_back({ii + i, jj + j});
            }
        }
    }

    // for (auto i : adj)
    //         cout << i.first << i.second << ' ';
    //
    //     cout << endl;

    for (auto i : adj)
    {
        if (visited[i.first][i.second] == false)
        {
            check(arr, sum, i.first, i.second, visited);
        }
    }
}

void solve()
{
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cin >> arr[i][j];
        }
    }
    int ans = 0;

    rep(i, 0, n) rep(j, 0, m)
    {
        if (arr[i][j] && visited[i][j] == false)
        {
            int sum = 0;
            check(arr, sum, i, j, visited);
            ans = max(ans, sum);
            // cout << i << ' ' << j << sum << endl;
        }
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
    {
        solve();
    }

    return 0;
}
