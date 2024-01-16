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

    vector<int> a(max(11, n + 1), 1e9);
    a[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i <= 9)
            a[i] = 1;
        else
        {
            set<int> dig;
            int num = i;
            while (num != 0)
            {
                dig.insert(num % 10);
                num /= 10;
            }
            for (auto j : dig)
                a[i] = min(a[i - j] + 1, a[i]);
        }
    }
    cout << a[n] << endl;
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
