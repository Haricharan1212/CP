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
    int x = n;

    if (n % 2 == 0)
    {
        for (int i = n - 2; i >= 1; i--)
        {
            cout << i << ' ';
        }
    }
    else
    {
        cout << 1 << ' ';
        for (int i = n - 2; i >= 2; i--)
        {
            cout << i << ' ';
        }
    }
    cout << n - 1 << ' ' << n << endl;
    return;
    vi a;

    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(i + 1);

    int i;
    for (i = n - 1; i >= 0; i--)
    {
        a.push_back(x);
        s.erase(x);
        x = (x + 1) / 2;
        if (x / 2 == 1)
        {
            break;
        }
    }

    if (s.size() % 2 == 0)
    {
        for (auto it = s.rbegin(); it != s.rend(); it++)
            cout << *it << " ";
    }
    else
    {
        cout << *s.begin() << ' ';
        s.erase(s.begin());
        for (auto it = s.rbegin(); it != s.rend(); it++)
            cout << *it << " ";
    }

    for (int i = 0; i < a.size(); i++)
        cout << a[a.size() - 1 - i] << ' ';

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
