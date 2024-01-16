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
        cin >> a[i];

    int l = 0;
    int r = 1e9;

    vi b = a;
    sort(b.begin(), b.end());
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }

    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] < a[i])
        {
            r = min(r, (a[i] + a[i - 1]) / 2);
        }
        else if (a[i - 1] > a[i])
        {
            l = max(l, (a[i] + a[i - 1] + 1) / 2);
        }
    }

    if (l <= r)
    {
        cout << r << endl;
    }
    else
        cout << -1 << endl;
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
