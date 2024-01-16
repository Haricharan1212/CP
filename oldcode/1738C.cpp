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
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a % 2 == 1 || a % 2 == -1)
            odd++;
        else
            even++;
    }

    if (n % 2 == 0)
    {
        if (odd % 2 == 1)
        {
            cout << "Alice" << endl;
            return;
        }
        else
        {
            if (odd % 4 == 2)
            {
                cout << "Bob" << endl;
            }
            else
                cout << "Alice" << endl;
        }
    }
    else
    {
        if (odd % 4 == 1 || odd % 4 == 2 || (odd == n && odd % 4 == 1))
            cout << "Bob" << endl;
        else
            cout << "Alice" << endl;
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
