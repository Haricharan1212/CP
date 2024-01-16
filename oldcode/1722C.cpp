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
    map<string, set<int>> m;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        // Do something with the input
    }
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        // Do something with the input
    }
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        // Do something with the input
    }

    int a = 0, b = 0, c = 0;
    for (auto i : m)
    {
        set<int> x = i.second;

        if (x.size() == 2)
        {
            if (x.count(0))
                a++;
            if (x.count(1))
                b++;
            if (x.count(2))
                c++;
        }
        if (x.size() == 1)
        {
            if (x.count(0))
                a += 3;
            if (x.count(1))
                b += 3;
            if (x.count(2))
                c += 3;
        }
    }
    cout << a << ' ' << b << ' ' << c << endl;
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
