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
    vi a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vi mn(n, 0), mx(n, 0);

    for (int i = 0; i < n; i++)
        mn[i] = *lower_bound(b.begin(), b.end(), a[i]) - a[i];

    int prev = n - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        int x = upper_bound(b.begin(), b.end(), a[i]) - b.begin();

        if (b[x - 1] == a[i])
            prev = x;
        else if (x == i && i != 0)
        {
            prev = x - 1;
        }

        mx[i] = b[prev] - a[i];
    }

    for (auto i : mn)
        cout << i << ' ';
    cout << endl;
    for (auto i : mx)
        cout << i << ' ';
    cout << endl;
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
