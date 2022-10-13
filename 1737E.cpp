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

int modInverse(int A)
{
    int M = 1e9 + 7;
    int m0 = M;
    int y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1)
    {
        // q is quotient
        int q = A / M;
        int t = M;

        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}

// 0 4/16 4/16 8/16

void solve()
{
    int n;
    cin >> n;
    cout << 0 << endl;
    int p, q;
    if (n % 2 == 0)
    {
        for (int i = 1; i < n - 1; i++)
        {
            p = 1;
            q = n;
            cout << p * modInverse(q) % ((int)1e9 + 7) << endl;
        }
        p = 1;
        q = n / 2;
        cout << p * modInverse(q) % ((int)1e9 + 7) << endl;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            p = 1;
            q = n - 1;
            cout << p * modInverse(q) % ((int)1e9 + 7) << endl;
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
