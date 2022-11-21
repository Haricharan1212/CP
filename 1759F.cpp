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
    int n, p;
    cin >> n >> p;

    set<int> s;
    int a;
    int x = 0, y;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        s.insert(a);
        if (i == n - 2)
            x = a;
        if (i == n - 1)
            y = a;
    }

    if (y <= 100)
    {
        // cycling not required
        int flag = 1;
        for (int i = 0; i < y; i++)
            if (s.count(i))
                continue;
            else
            {
                flag = 0;
                break;
            }
        if (flag == 1)
        {
            cout << *s.upper_bound(y) - y - 1 << endl;
            return;
        }
    }

    int num = y;
    int cn = 0;
    while (s.count(num))
    {
        num--;
        cn++;
        if (num == -1)
            num = p - 1;
        if (cn == p)
            break;
    }

    cout << p - cn << endl;
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
