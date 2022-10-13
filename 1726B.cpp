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
    ll n, m;
    cin >> n >> m;

    if (m % n == 0)
    {
        {
            cout << "Yes" << endl;
            for (ll i = 0; i < n; i++)
                cout << m / n << ' ';
            cout << endl;
        }
    }
    else if (n > m)
        cout << "No" << endl;
    else if (1)
    {
        if (n % 2 == 0 && m % 2 == 0)
        {
            cout << "Yes" << endl;
            for (ll i = 0; i < n - 2; i++)
                cout << 1 << ' ';
            cout << (m - n + 2) / 2 << ' ' << (m - n + 2) / 2 << ' ' << endl;
        }
        else if (n % 2 == 1)
        {
            cout << "Yes" << endl;
            for (ll i = 0; i < n - 1; i++)
                cout << 1 << ' ';
            cout << (m - n + 1) << ' ' << endl;
        }
        else
            cout << "No" << endl;
    }

    else
        cout << "No" << endl;
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
