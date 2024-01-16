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
    int a, b;
    cin >> a >> b;

    int arr[a + 1][b + 1] = {0};

    for (int i = 0; i <= a; i++)
        for (int j = 0; j <= b; j++)
        {
            arr[i][j] = 1e9;
            if (i == 0 || j == 0 || i == j)
                arr[i][j] = 0;
            else if (i == 1)
                arr[i][j] = j - 1;
            else if (j == 1)
                arr[i][j] = i - 1;
            else
            {
                for (int k = 1; k <= min(i, j); k++)
                {
                    if (k != min(i, j))
                    {
                        arr[i][j] = min(arr[i][j], 2 + arr[i - k][k] + arr[i][j - k]);
                        arr[i][j] = min(arr[i][j], 2 + arr[k][j - k] + arr[i - k][j]);
                    }
                    else
                    {
                        if (i < j)
                            arr[i][j] = min(arr[i][j], 1 + arr[i - k][k] + arr[i][j - k]);
                        else
                            arr[i][j] = min(arr[i][j], 1 + arr[k][j - k] + arr[i - k][j]);
                    }
                }
            }
        }
    // for (int i = 0; i <= a; i++)
    // {
    //     for (int j = 0; j <= b; j++)
    //         cout << arr[i][j] << ' ';
    //     cout << endl;
    // }
    cout << arr[a][b];
}

int main()
{
    fio;
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int tc = 1;
    //    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
