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

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    int odd = 1e9 + 7, even = 1e9 + 7;
    int oddnum = 1e9 + 7, evennum = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 1 && oddnum > a[i])
            odd = i, oddnum = a[i];
        else if (a[i] % 2 == 0 && evennum > a[i])
            even = i, evennum = a[i];
    }
    if (odd == 1e9 + 7 || even == 1e9 + 7)
    {
        cout << n - 1 << endl;
        for (int i = 1; i < n; i++)
        {
            cout << i << ' ' << n << endl;
        }
    }
    else
    {

        cout << n - 1 << endl;
        cout << 1 << ' ' << n << endl;
        if ((a[0] + a[n - 1]) % 2 == 0)
        {
            a[0] = a[n - 1];
        }
        else
        {
            a[n - 1] = a[0];
        }

        for (int i = 2; i < n; i++)
        {
            if ((a[i - 1] + a[0]) % 2 == 1)
            {
                cout << 1 << ' ' << i << endl;
            }
            else
            {
                cout << i << ' ' << n << endl;
            }
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
