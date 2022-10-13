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

    string s;
    cin >> s;
    int w, m;
    cin >> w >> m;
    int n = s.size();

    vi a(n - w + 1);

    int arr[9] = {0};

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            a[i] = s[i] - '0';
        else
            a[i] = a[i - 1] + (s[i] - '0');

        if (arr[a[i] % 9] == 0)
            arr[a[i] % 9] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;

        int v = (a[r - 1] - (l == 1 ? 0 : a[l - 2])) % 9;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << v << endl;
                if (i == j)
                    continue;
                if ((arr[i] * v + arr[j]) % 9 == k)
                {
                    cout << i + 1 << ' ' << j + 1 << endl;
                    goto lin;
                }
            }
        }
        cout << "-1 -1" << endl;
    lin:
    {
    }
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
