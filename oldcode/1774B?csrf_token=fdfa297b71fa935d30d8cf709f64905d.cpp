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
    int n, m, k;
    cin >> n >> m >> k;

    vi a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());

    int cnt = 0;
    int b = n / k;
    int e = n % k;

    for (int i = 0; i < m; i++)
    {
        if (a[i] > b + 1)
        {
            cout << "NO" << endl;
            return;
        }
        else if (a[i] > b)
            e--;
    }

    // for (int i = m % k; i < m; i++)
    // {
    //     if (a[i] <= (n - 1) / k)
    //         continue;
    //     else
    //     {
    //         cout << "NO" << endl;
    //         return;
    //     }
    // }

    if (e >= 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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
