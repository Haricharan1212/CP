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

    multiset<int> s;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s.insert(a);
    }

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    int k = 0;

    for (k; k <= n; k++)
    {

        auto se = s;
        for (int i = 1; i <= k; i++)
        {

            // for (auto i : se)
            //     cout << i << ' ';
            // cout << endl;

            if (se.upper_bound(k - i + 1) == se.begin())
            {
                cout << k - 1 << endl;
                return;
            }
            se.erase(--se.upper_bound(k - i + 1));
            int num = *se.begin();
            se.erase(se.begin());
            se.insert(num + (k - i + 1));
        }
    }
    cout << n << endl;
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
