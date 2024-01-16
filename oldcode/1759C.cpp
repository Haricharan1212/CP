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
    int l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;

    if (b - a == 0)
    {
        cout << 0 << endl;
    }
    else if (abs(b - a) >= x)
    {
        cout << 1 << endl;
    }
    else
    {
        int z = min(a, b);
        int y = max(a, b);
        a = z;
        b = y;

        if ((r - b) >= x || (a - l) >= x)
            cout << 2 << endl;
        else
        {
            if ((r - a) >= x && (b - l) >= x)
                cout << 3 << endl;
            else
                cout << -1 << endl;
        }
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
