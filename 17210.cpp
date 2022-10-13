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
    string x, b;
    cin >> x >> b;

    vi a;
    map<char, int> m;
    m[x[0]]++;
    m[x[1]]++;
    m[b[0]]++;
    m[b[1]]++;
    for (auto i : m)
        a.push_back(i.second);
    sort(a.begin(), a.end(), greater<int>());

    if (a[0] == 4)
    {
        cout << 0 << endl;
        return;
    }
    if (a[0] == 3)
    {
        cout << 1 << endl;
        return;
    }
    if (a.size() == 2)
    {
        cout << 1 << endl;
        return;
    }
    if (a.size() == 4)
        cout << 3 << endl;
    if (a.size() == 3)
        cout << 2 << endl;
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
