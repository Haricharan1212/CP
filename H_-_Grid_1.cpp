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

void solve()
{
    int h, w;
    cin >> h >> w;

    int arr[h][w];
    for (int i = 0; i < h; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < w; j++)
            arr[i][j] = (s[j] == '.' ? 0 : 1);
    }
    vector<vector<int>> dp(h + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
        {
            if (i == 1 && j == 1)
                dp[i][j] = 1;
            else
                dp[i][j] = (arr[i - 1][j - 1] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1]);
            dp[i][j] %= ((int)1e9 + 7);
        }

    cout << dp[h][w];
}
int main()
{
    fio;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
