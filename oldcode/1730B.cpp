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

    vi x(n);
    vi t(n);

    map<int, int> m;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> t[i];

    for (int i = 0; i < n; i++)
    {
        m[x[i]] = max(t[i], m[x[i]]);
    }

    cout << setprecision(10) << fixed;

    long double ans = (*m.begin()).first;
    long double time = (*m.begin()).second;
    for (auto i : m)
    {
        if (i.first - ans + i.second <= time)
            continue;
        else if (i.first - ans + time <= i.second)
        {
            ans = i.first;
            time = i.second;
        }
        else
        {
            ans = (i.first + ans + i.second - time) / 2.0;
            time = i.first - ans + i.second;
        }
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
