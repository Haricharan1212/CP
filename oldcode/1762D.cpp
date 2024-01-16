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
    cout.flush();
    int n;
    cin >> n;

    if (n == 2)
    {
        cout << "! 1 2" << endl;
        cout.flush();
        return;
    }

    int i = 1, j = 2;

    for (int k = 3; k <= n; k++)
    {
        int x, y;

        cout << "? " << i << ' ' << k << endl;
        cout.flush();
        cin >> x;

        cout << "? " << j << ' ' << k << endl;
        cout.flush();
        cin >> y;

        if (x == y)
            continue;
        else if (x > y)
            j = k;
        else
            i = k;
    }
    cout << "! " << i << ' ' << j << endl;
    cout.flush();
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
        int x;
        cin >> x;

        cout.flush();
    }

    return 0;
}
