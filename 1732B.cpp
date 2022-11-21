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
    int sum = 0;
    string s;
    cin >> s;

    for (int i = 0; i < n; i++)
        a[i] = s[i] - '0', sum += a[i];

    int x = 0, y = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == 0 && a[i + 1] == 1)
            x++;
        else if (a[i] == 1 && a[i + 1] == 0)
            y++;
    }
    int f = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == 0 && a[i + 1] == 1)
        {
            f = 1;
            break;
        }
        else if (a[i] == 1 && a[i + 1] == 0)
        {
            f = 2;
            break;
        }
    }
    cout << x + y + (x >= y && f == 1 ? -1 : 0) << endl;
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
