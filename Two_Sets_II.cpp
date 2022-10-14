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
    int n;
    cin >> n;

    vi dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (i <= 2)
            continue;
        // else if (i == 3)
        //     dp[i] = 1;
        else if (i == 4 || i == 3)
            dp[i] = 1;
        else if (i % 4 == 1 || i % 4 == 2)
            dp[i] = 0;
        else
        {
            for (auto i : dp)
                cout << i << ' ';
            cout << endl;

            for (int j = 1; j <= i; j++)
            {
                int sum = j * (j + 1) / 2;
                int a = (-1 + sqrt(1 + 4 * 2 * sum / 2)) / 2;
                int b = (-1 + sqrt(1 + 4 * 2 * (sum / 2 - j))) / 2;
                cout << a << ' ' << b << endl;
            }
            dp[i] = dp[b] + dp[a];
        }
    }
    cout << dp[n];
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
