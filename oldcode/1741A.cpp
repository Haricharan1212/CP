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
    string a, b;
    cin >> a >> b;

    if (a == b)
    {
        cout << "=" << endl;
        return;
    }
    char c = a[a.size() - 1], d = b[b.size() - 1];
    if (c == d && c == 'S')
    {
        if (a.size() > b.size())
            cout << "<" << endl;
        else
            cout << ">" << endl;
        return;
    }
    if (c == d && c == 'L')
    {
        if (a.size() > b.size())
            cout << ">" << endl;
        else
            cout << "<" << endl;
        return;
    }
    if (c == d && c == 'M')
    {
        cout << "=" << endl;
        return;
    }
    if (c == 'S' || (c == 'M' && d == 'L'))
        cout << "<" << endl;
    else
        cout << ">" << endl;
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
