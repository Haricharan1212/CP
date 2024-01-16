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
    int n, q;
    cin >> n >> q;

    ll arr[1005][1005] = {0};
    for (int i = 0; i < n; i++)
    {
        ll h, w;
        cin >> h >> w;
        arr[h][w] += h * w;
    }
    for (int i = 1; i < 1004; i++)
        for (int j = 1; j < 1004; j++)
        {
            arr[i][j] = arr[i][j] + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }

    for (int i = 0; i < q; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << arr[c - 1][d - 1] - arr[c - 1][b] - arr[a][d - 1] + arr[a][b] << endl;
    }
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
