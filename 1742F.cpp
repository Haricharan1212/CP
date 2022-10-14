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
    ll q;
    cin >> q;
    ll a = 1, b = 1;
    ll a1 = 0, a2 = 0, count1 = 1, count2 = 1;
    for (int j = 0; j < q; j++)
    {
        ll type, k;
        string f;
        cin >> type >> k >> f;
        if (type == 1)
        {
            for (auto i : f)
                if (i == 'a')
                    count1 += k;
                else
                    a1 = 1;
        }
        else
        {
            for (auto i : f)
                if (i == 'a')
                    count2 += k;
                else
                    a2 = 1;
        }
        if (a2 == 1)
        {
            cout << "YES" << endl;
        }
        else if (a1 == 0 && count1 < count2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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
