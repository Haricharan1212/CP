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

    vector<vector<ll>> a(n, vector<ll>(n, 0));
    vector<vector<ll>> b(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
            a[i][j] = (s[j] == '.' ? 0 : 1);
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i][0] == 0)
            b[i][0] = 1;
        else
        {
            for (int j = i; j < n; j++)
                b[j][0] = 0;
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[0][i] == 0)
            b[0][i] = 1;
        else
        {
            for (int j = i; j < n; j++)
                b[0][j] = 0;
            break;
        }
    }

    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
        {
            if (a[i][j] == 0)
                b[i][j] = b[i - 1][j] + b[i][j - 1];
            else
                b[i][j] = 0;
            b[i][j] %= (int)(1e9 + 7);
        }
    cout << b[n - 1][n - 1];
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
