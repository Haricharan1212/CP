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
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    vi b;
    int ans = 0;
    for (int i = 0; i < n; i += 2)
    {
        if (abs(a[i] - a[i + 1]) == 1 && (a[i] + a[i + 1]) % 4 == 3)
        {
            if (a[i] > a[i + 1])
                ans++;
            b.push_back(max(a[i], a[i + 1]) / 2);
        }
        else
        {
            cout << -1 << endl;
            return;
        }
    }

    int num = ceil(log2(n));

    for (int i = 0; i <= num; i++)
    {
        vi c;
        if (b.size() == 1)
            break;
        for (int i = 0; i < b.size(); i += 2)
        {
            if (abs(b[i] - b[i + 1]) <= 1)
            {
                if (b[i] > b[i + 1])
                    ans++;
                c.push_back(max(b[i], b[i + 1]) / 2);
            }
            else
            {
                cout << -1 << endl;
                return;
            }
        }

        b = c;
    }
    cout << ans << endl;
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
