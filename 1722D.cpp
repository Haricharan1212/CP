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
    int n1 = a.size();
    int n2 = b.size();

    int arr[n1 + 1][n2 + 1] = {0};

    for (int i = 1; i <= n1; i++)
        for (int j = 1; j <= n2; j++)
        {
            arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]) + (a[i - 1] == b[j - 1] ? 1 : 0);
        }
    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
            cout << arr[i][j] << ' ';
        cout << endl;
    }
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
