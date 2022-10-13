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
    multiset<int> a, b;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        a.insert(x);
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (a.count(x))
        {
            a.erase(a.find(x));
            continue;
        }
        b.insert(x);
    }

    int arra[10] = {0};
    int arrb[10] = {0};

    for (auto i : a)
    {
        if (i >= 10)
        {
            i = floor(log10(i)) + 1;
            count++;
        }
        arra[i]++;
    }
    for (auto i : b)
    {
        if (i >= 10)
        {
            i = floor(log10(i)) + 1;
            count++;
        }
        arrb[i]++;
    }

    for (int i = 2; i < 10; i++)
    {
        count += abs(arra[i] - arrb[i]);
    }

    cout << count << endl;
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
