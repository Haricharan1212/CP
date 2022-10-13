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
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();

    int arr[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0)
                arr[i][j] = j;
            else if (j == 0)
                arr[i][j] = i;
            else if (a[i - 1] == b[j - 1])
                arr[i][j] = arr[i - 1][j - 1];
            else
                arr[i][j] = 1 + min(arr[i - 1][j - 1], min(arr[i][j - 1], arr[i - 1][j]));
        }
    }

    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //         cout << arr[i][j] << ' ';
    //     cout << endl;
    // }
    cout << arr[n][m];
}

int main()
{
    fio;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //   cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
