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

    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int arr[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                arr[i][j] = 0;
            else if (i == j)
                arr[i][j] = a[j - 1];
            else
            {
                arr[i][j] = max(arr[i + 1][j] + a[i - 1], arr[i][j - 1] + a[j - 1]);
            }
        }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            cout << arr[i][j] << ' ';
        cout << endl;
    }
    cout << arr[1][n] << endl;
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
