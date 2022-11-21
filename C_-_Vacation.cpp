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
    int ans = 0;
    int current = 0;

    int arr[n][3];

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (i == 0)
        {
            arr[0][0] = a;
            arr[0][1] = b;
            arr[0][2] = c;
            continue;
        }
        arr[i][0] = max(arr[i - 1][1], arr[i - 1][2]) + a;
        arr[i][1] = max(arr[i - 1][0], arr[i - 1][2]) + b;
        arr[i][2] = max(arr[i - 1][1], arr[i - 1][0]) + c;
    }
    cout << max(arr[n - 1][0], max(arr[n - 1][1], arr[n - 1][2]));
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
