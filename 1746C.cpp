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
    set<int> empty;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        empty.insert(i);
    }

    vi z(n);
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            int diff = a[i] - a[i + 1];
            int val = *empty.lower_bound(diff);
            z[val] = i + 1;
            empty.erase(val);
        }
    }

    for (auto i : z)
        cout << i + 1 << ' ';
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
