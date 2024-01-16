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
    int n, m;
    cin >> n >> m;

    multiset<int> s;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s.insert(a);
    }
    for (int i = 0; i < m; i++)
    {
        int f;
        cin >> f;

        auto z = s.upper_bound(f);
        if (s.size() == 0)
        {
            cout << -1 << endl;
            continue;
        }
        if (z == s.begin())
        {
            cout << -1 << endl;
            continue;
        }
        z--;
        cout << *z << endl;
        s.erase(z);
    }
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
