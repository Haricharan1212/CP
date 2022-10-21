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
    int n, m;
    cin >> n >> m;

    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0 || (i % 2 == 1 && j % 2 == 1))
                dp[i][j] = 0;
            else if (i == 1)
                dp[i][j] = j / 2;
            else if (j == 1)
                dp[i][j] = i / 2;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 2] - dp[i - 1][j - 2] + dp[i][j - 1] + dp[i - 2][j] - dp[i - 2][j - 1];
        }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            cout << dp[i][j] << ' ';
        cout << endl;
    }

    cout << dp[2][2];
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
