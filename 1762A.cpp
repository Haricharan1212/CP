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
    int oddcount = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 1)
            oddcount++;
    }

    map<int, int> m;
    int mincount = 1e9;
    for (int i = 0; i < a.size(); i++)
    {
        int count = 0;
        if (a[i] % 2 == 0)
            while (a[i] % 2 != 1)
            {
                count++;
                a[i] /= 2;
            }
        else
        {
            while (a[i] % 2 != 0)
            {
                count++;
                a[i] /= 2;
            }
        }

        m[a[i]] = count;
        mincount = min(count, mincount);
    }

    if (oddcount % 2 == 0)
        cout << 0 << endl;
    else
        cout << mincount << endl;
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
