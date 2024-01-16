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

    int arr[1001] = {0};
    for (int i = 0; i <= 1000; i++)
        arr[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int f;
        cin >> f;
        arr[f] = max(arr[f], i);
    }

    int ans = -1;
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = i; j <= 1000; j++)
        {
            if (arr[j] == -1 || arr[i] == -1)
                continue;
            else
            {
                if (__gcd(i, j) == 1)
                {
                    //                    cout << i << ' ' << j << endl;
                    ans = max(ans, arr[i] + arr[j]);
                }
            }
        }
    }
    if (ans == -1)
        cout << ans << endl;
    else
        cout << ans + 2 << endl;
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
